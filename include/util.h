#pragma once

#include <string>
#include <cstring>
#include <unistd.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <net/if.h>
#include <sys/ioctl.h>

class CANOpenMessage{
public:
  uint32_t can_id;
  size_t length = 8;
  uint8_t data[8];
};


class Subscription{
public:
  std::string signal_name;
  uint32_t subscriber_id;
  size_t length;
  uint16_t value;
  uint8_t pos;
  double scale;
  int8_t offset;
  
  uint16_t return_16(uint16_t val){
    return val & 0xffff;
  }
  
  uint8_t return_8(uint8_t val){
    return val & 0xff;
  }

  
};

struct canopen_throttle{
  uint8_t control_mode; // this will be in the first two bits but who cares
  uint8_t speed_low;
  uint8_t speed_high;
  // seperated into lows and high's so we wouldn't
  // have to deal with the reversed byte ordering
  uint8_t arc;
};


bool addToEpoll(int epfd, int fd);

int openCanSocket(const char* iface);
