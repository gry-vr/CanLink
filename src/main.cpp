#include <iostream>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <chrono>


#include "../include/decoding.h"
#include "../include/dura_max.h"
#include "../include/MessageHandler.h"

#include "../include/util.h"





// Set up subscriptions for dashboard display (ID: 0x300)
std::vector<Subscription> eec5_subs = {
    Subscription{
        .signal_name = "engine_turbocharger_1_calculated",
        .subscriber_id = 0x300,
        .length = 16,
        .value = 16,
        .pos = 2,
        .scale = 1,
        .offset = 0},    // Fixed narrowing conversion

    Subscription{
        .signal_name = "commanded_vgt_position",
        .subscriber_id = 0x400,
        .length = 16,
        .value = 16,
        .pos = 0,
        .scale = 1,
        .offset = 0},

    Subscription{
        .signal_name = "engine_variable_geometry_turboch",
        .subscriber_id = 0x400,
        .length = 8,
        .value = 0,
        .pos =  7,
        .scale = 1,
        .offset = 0}
};






void configure_handler(MessageHandler& handler);

void set_subscriptions(MessageHandler& handler);
void set_pgn_owners(MessageHandler& handler);


int main(int argc, char* argv[]) {


    
    MessageHandler handler;

    // Initialize EngineData PGN Owner

    set_subscriptions(handler);
    set_pgn_owners(handler);



    // Initialize outgoing message for dashboard

    handler.set_outgoing_message(0x300, {});
    handler.set_outgoing_message(0x400, {});






    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <can0> <can1>\n";
        return 1;
    }

    // Open two CAN sockets
    int sock_can0 = openCanSocket(argv[1]);
    int sock_can1 = openCanSocket(argv[2]);
    if (sock_can0 < 0 || sock_can1 < 0) {
        std::cerr << "Failed to open CAN sockets.\n";
        close(sock_can0);
        close(sock_can1);
        return 1;
    }

    // Create an epoll instance
    int epfd = epoll_create1(0);
    if (epfd < 0) {
        perror("epoll_create1");
        close(sock_can0);
        close(sock_can1);
        return 1;
    }

    // Add sockets to epoll
    if (!addToEpoll(epfd, sock_can0) || !addToEpoll(epfd, sock_can1)) {
        std::cerr << "Failed to add sockets to epoll.\n";
        close(epfd);
        close(sock_can0);
        close(sock_can1);
        return 1;
    }

    constexpr int MAX_EVENTS = 16;
    struct epoll_event events[MAX_EVENTS];

    std::cout << "Forwarding messages between " << argv[1] << " and " << argv[2] << ".\n";

    bool running = true;
    while (running) {
        int nfds = epoll_wait(epfd, events, MAX_EVENTS, -1);  // Wait indefinitely
        if (nfds < 0) {
            if (errno == EINTR) {
                running = false;  // Exit gracefully on signal
                break;
            }
            perror("epoll_wait");
            break;
        }

        for (int i = 0; i < nfds; i++) {
            int fd = events[i].data.fd;

            if (events[i].events & EPOLLIN) {

                struct can_frame frame;
                auto start_time = std::chrono::high_resolution_clock::now();
                ssize_t nbytes = read(fd, &frame, sizeof(frame));
                
                if (nbytes < 0) {
                    perror("read");
                    continue;
                } else if (nbytes == 0) {
                    std::cerr << "Socket closed unexpectedly.\n";
                    running = false;
                    break;
                }

                // Determine the output socket
                int outSock = (fd == sock_can0) ? sock_can1 : sock_can0;

                std::cout << "ID incoming " << (frame.can_id & CAN_EFF_MASK) << "\n";
                
                handler.handleIncoming(frame);



                std::vector<CANOpenMessage> outgoing = handler.getAllOutgoingMessages();
                
                for(auto& message : outgoing)
                {   // Forward the frame to the other socket
                    frame.can_id = message.can_id;
                    memcpy(&frame.len, &message.length, sizeof(message.length) );
                    memcpy(&frame.data, &message.data, 8);

                    std::cout << "FINNA SEND\n";
                    std::cout << "outgoing id: " << frame.can_id << "\n";
                    std::cout << "outgoing dlc: " << frame.can_dlc << "\n";
                    for(int i = 0; i < 8; i++){
                        std::cout << "outgoing data[" << i << "] " << frame.data[i] << "\n";
                    }

                    ssize_t bytesWritten = write(outSock, &frame, sizeof(frame));

                    if (bytesWritten < 0) {
                        std::cerr << "write" << "\n";
                    }
                }
                auto end_time = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time-start_time);
                std::cout << "TIME TO TRANSLATE: " << duration.count() << "\n";
            }
        }
    }

    close(epfd);
    close(sock_can0);
    close(sock_can1);

    std::cout << "Terminated.\n";
    return 0;
}







void set_subscriptions(MessageHandler& handler){
    handler.set_subscriptions(DURA_MAX_EEC5_ELECTRONIC_ENGINE_CONTROL_5_FRAME_ID, eec5_subs);

}

void set_pgn_owners(MessageHandler& handler){
    handler.add_pgn_owner<dura_max_eec5_electronic_engine_control_5_t>(
        DURA_MAX_EEC5_ELECTRONIC_ENGINE_CONTROL_5_FRAME_ID,  // CAN ID for engine data
        dura_max_eec5_electronic_engine_control_5_init,
        dura_max_eec5_electronic_engine_control_5_unpack,
        decode_dura_max_eec5_electronic_engine_control_5
    );
}

