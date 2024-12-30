#include "../include/util.h"


// Function to open a CAN socket
int openCanSocket(const char* iface) {
    int sock = socket(PF_CAN, SOCK_RAW | SOCK_NONBLOCK, CAN_RAW);
    if (sock < 0) {
        perror("socket");
        return -1;
    }

    struct ifreq ifr;
    std::strncpy(ifr.ifr_name, iface, IFNAMSIZ);
    if (ioctl(sock, SIOCGIFINDEX, &ifr) < 0) {
        perror("ioctl");
        close(sock);
        return -1;
    }

    struct sockaddr_can addr = {};
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close(sock);
        return -1;
    }

    return sock;
}


// Function to add a socket to epoll
bool addToEpoll(int epfd, int fd) {
    struct epoll_event ev = {};
    ev.events = EPOLLIN;  // Interested in read events
    ev.data.fd = fd;
    if (epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &ev) < 0) {
        perror("epoll_ctl");
        return false;
    }
    return true;
}
