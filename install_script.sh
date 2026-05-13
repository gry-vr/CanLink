#!/usr/bin/env bash

set -Eeuo pipefail

APP_NAME="canlink"
REPO_URL="https://github.com/gry-vr/CanLink.git"
PREFIX="/usr/local"
SYSTEMD_LOCATION="/etc/systemd/system/"

die() { echo "error: $*" >&2; exit 1; }

need_cmd() { command -v "$1" >/dev/null 2>&1 || die "missing dependency: $1"; }

as_root() { sudo -- "$@"; }

main() {

  need_cmd git
  need_cmd sudo

  as_root apt-get update
  as_root apt-get upgrade
  as_root apt-get install -y --no-install-recommends \
  build-essential cmake pkg-config neovim tmux
   
  tmp="$(mktemp -d)" 
  trap 'rm -rf "$tmp"' EXIT

  # depth is the depth of the commit history since we don't care when we deploy
  # We can do depth 1 here
  git clone --depth 1 "$REPO_URL" "$tmp/$APP_NAME"
  cd "$tmp/$APP_NAME"
  printf 'working directory %s' "$tmp/$APP_NAME"
  if [ -f Makefile ] || [ -f makefile ]; then
    make -j"$(nproc)"
    BIN="$tmp/$APP_NAME/canlink"
    [ -x "$BIN" ] || die "expected executable not found: $BIN"
    as_root install -D -m 0755 "$BIN" "$PREFIX/bin/" 
  else
    die "no recognized build system (no Makefile)"
  fi

  printf 'installed canlink in /usr/local/bin \n' 

  printf 'making changes to config.txt for CANHAT! \n'

  config_lines="$tmp/$APP_NAME/resources/append.txt"
  as_root tee -a /boot/firmware/config.txt < "$config_lines" >/dev/null

  printf 'creating systemd service'
  
  as_root mv "$tmp/$APP_NAME/resources/setup_can_and_run.service" "$SYSTEMD_LOCATION"
  as_root systemctl daemon-reload
  as_root systemctl enable setup_can_and_run.service

  printf 'Installed and systemd service ready!\n reboot required!\n'
}

main "$@"
