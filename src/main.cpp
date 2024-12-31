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




std::vector<Subscription> amb_subs = {
    Subscription{
        .signal_name = "barometric_pressure_barometric_pr",
        .subscriber_id = 0x307,
        .length = 16,
        .value = 0,
        .pos = 0,
        .scale = 0.1, // kPa to mBar
        .offset = 0,
    },
    Subscription{
        .signal_name = "ambient_air_temperature",
        .subscriber_id = 0x30B,
        .length = 8,
        .value = 0,
        .pos = 3,
        .scale = 1,
        .offset = 0
    }
};


std::vector<Subscription> eec1_subs = {
    Subscription{
        .signal_name = "engine_speed",
        .subscriber_id = 0x300,
        .length = 16,
        .value = 0,
        .pos = 0,
        .scale = 1,
        .offset = 0
    },

};

std::vector<Subscription> eec2_subs = {};

std::vector<Subscription> eec3_subs = {};

std::vector<Subscription> eec5_subs = {
    Subscription{
        .signal_name = "actual_vgt_position",
        .subscriber_id = 0x302,
        .length = 8,
        .value = 0,
        .pos = 6,
        .scale = 1,
        .offset = 0
    },

};

std::vector<Subscription> eec9_subs = {
    Subscription{
        .signal_name = "commanded_fuel_rail_pressure",
        .subscriber_id = 0x303,
        .length = 16,
        .value = 0,
        .pos = 0,
        .scale = 1e8, // mPa to Bar
        .offset = 0
    },
};

std::vector<Subscription> eec20_subs = {};

std::vector<Subscription> cac1_subs = {};

std::vector<Subscription> easi_subs = {};

std::vector<Subscription> ebcc_subs = {
    Subscription{
        .signal_name = "desired_boost_pressure",
        .subscriber_id = 0x307,
        .length = 16,
        .value = 0,
        .pos = 4,
        .scale = 0.1, // kPa -> mBar
        .offset = 0
    }
};

std::vector<Subscription> efl_p1_subs = {
    Subscription{
        .signal_name = "eng_oil_press",
        .subscriber_id = 0x30B,
        .length = 8,
        .value = 0,
        .pos = 4,
        .scale = 0.25,
        .offset = 0 
    },
};

std::vector<Subscription> efl_p2_subs = {};

std::vector<Subscription> et1_subs = {
    Subscription{
        .signal_name = "eng_coolant_temp",
        .subscriber_id = 0x30B,
        .length = 8,
        .value = 0,
        .pos = 0,
        .scale = 1, // degC,
        .offset = 0
    },
    Subscription{
        .signal_name = "eng_fuel_temp1",
        .subscriber_id = 0x30B,
        .length = 8,
        .value = 0,
        .pos = 1,
        .scale = 1,
        .offset = 0
    },
};

std::vector<Subscription> et3_subs = {};

std::vector<Subscription> ic1_subs = {
    Subscription{
        .signal_name = "eng_intake_manifold1_press",
        .subscriber_id = 0x300,
        .length = 16,
        .value = 0,
        .pos = 4,
        .scale = 0.1,    // to go from Kpa to mBar
        .offset = 0
    },

};

std::vector<Subscription> lfe1_subs = {};

std::vector<Subscription> tci5_subs = {};

std::vector<Subscription> vep1_subs = {};





// We might want to have wheel_based_vehicle_speed from ccvs1_cruist_control_veh_spd





void configure_handler(MessageHandler& handler);

void set_subscriptions(MessageHandler& handler);
void set_pgn_owners(MessageHandler& handler);


int main(int argc, char* argv[]) {

    MessageHandler handler;

    // Initialize EngineData PGN Owner

    set_pgn_owners(handler);

    set_subscriptions(handler);
    


    // Initialize outgoing message for dashboard

    handler.set_outgoing_message(0x300,{});
    handler.set_outgoing_message(0x400,{}); // delete this one
    handler.set_outgoing_message(0x301,{});
    handler.set_outgoing_message(0x302,{});
    handler.set_outgoing_message(0x303,{});
    handler.set_outgoing_message(0x304,{});
    handler.set_outgoing_message(0x305,{});
    handler.set_outgoing_message(0x306,{});
    handler.set_outgoing_message(0x307,{});
    handler.set_outgoing_message(0x308,{});
    handler.set_outgoing_message(0x309,{});
    handler.set_outgoing_message(0x30B,{});
    handler.set_outgoing_message(0x30C,{});
    handler.set_outgoing_message(0x30D,{});

    // 30A is unused so therefore skipped

    handler.print_id_to_owner_map();

    handler.print_value_map();

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

                    // std::cout << "FINNA SEND\n";
                    // std::cout << "outgoing id: " << frame.can_id << "\n";
                    // std::cout << "outgoing dlc: " << frame.can_dlc << "\n";
                    // for(int i = 0; i < 8; i++){
                    //     std::cout << "outgoing data[" << i << "] " << frame.data[i] << "\n";
                    // }

                    ssize_t bytesWritten = write(outSock, &frame, sizeof(frame));

                    if (bytesWritten < 0) {
                        std::cerr << "write" << "\n";
                    }
                }
                auto end_time = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time-start_time);
                //std::cout << "TIME TO TRANSLATE: " << duration.count() << "\n";

                handler.print_value_map();
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
    handler.set_subscriptions(DURA_MAX_AMB_AMBIENT_CONDITIONS_FRAME_ID, amb_subs);
    handler.set_subscriptions(DURA_MAX_EEC1_ELECTRONIC_ENGINE_CONTROL_1_FRAME_ID, eec1_subs);
    handler.set_subscriptions(DURA_MAX_EEC2_ELECTRONIC_ENGINE_CONTROL_2_FRAME_ID, eec2_subs);
    handler.set_subscriptions(DURA_MAX_EEC3_ELECTRONIC_ENGINE_CONTROL_3_FRAME_ID, eec3_subs);
    handler.set_subscriptions(DURA_MAX_EEC5_ELECTRONIC_ENGINE_CONTROL_5_FRAME_ID, eec5_subs);

    handler.set_subscriptions(DURA_MAX_EEC9_ELECTRONIC_ENGINE_CONTROL_9_FRAME_ID, eec9_subs);
    handler.set_subscriptions(DURA_MAX_EEC20_ELECTRONIC_ENGINE_CONTROL__FRAME_ID, eec20_subs);
    handler.set_subscriptions(DURA_MAX_CAC1_CHARGE_AIR_COOLER_1_FRAME_ID, cac1_subs);
    handler.set_subscriptions(DURA_MAX_EASI_ENGINE_AIR_SYSTEM_INFO_FRAME_ID, easi_subs);
    handler.set_subscriptions(DURA_MAX_EBCC_ENGINE_EXHAUST_BRAKE_CONT_FRAME_ID, ebcc_subs);

    handler.set_subscriptions(DURA_MAX_EFL_P1_ENG_FLUID_LEVEL_PRESS_1_FRAME_ID, efl_p1_subs);
    handler.set_subscriptions(DURA_MAX_EFL_P2_ENG_FLUID_LEVEL_PRESS_2_FRAME_ID, efl_p2_subs);

    handler.set_subscriptions(DURA_MAX_ET1_ENGINE_TEMPERATURE_1_FRAME_ID, et1_subs);
    handler.set_subscriptions(DURA_MAX_ET3_ENGINE_TEMPERATURE_3_FRAME_ID, et3_subs);
    handler.set_subscriptions(DURA_MAX_IC1_INTAKE_EXHAUST_COND_1_FRAME_ID, ic1_subs);
    handler.set_subscriptions(DURA_MAX_LFE1_FUEL_ECONOMY_LIQUID_1_FRAME_ID, lfe1_subs);
    handler.set_subscriptions(DURA_MAX_TCI5_TURBOCHARGER_INFORMATION_5_FRAME_ID, tci5_subs);
    handler.set_subscriptions(DURA_MAX_VEP1_VEHICLE_ELECTRICAL_POWER_1_FRAME_ID, vep1_subs);

}

void set_pgn_owners(MessageHandler& handler){
    int counter = 0;
    handler.add_pgn_owner<dura_max_eec5_electronic_engine_control_5_t>(
        DURA_MAX_EEC5_ELECTRONIC_ENGINE_CONTROL_5_FRAME_ID,  // CAN ID for engine data
        dura_max_eec5_electronic_engine_control_5_init,
        dura_max_eec5_electronic_engine_control_5_unpack,
        decode_dura_max_eec5_electronic_engine_control_5
    );
    counter++;

    handler.add_pgn_owner<dura_max_amb_ambient_conditions_t>(
        DURA_MAX_AMB_AMBIENT_CONDITIONS_FRAME_ID,
        dura_max_amb_ambient_conditions_init,
        dura_max_amb_ambient_conditions_unpack,
        decode_dura_max_amb_ambient_conditions
    );
    counter++;

    handler.add_pgn_owner<dura_max_eec1_electronic_engine_control_1_t>(
        DURA_MAX_EEC1_ELECTRONIC_ENGINE_CONTROL_1_FRAME_ID,
        dura_max_eec1_electronic_engine_control_1_init,
        dura_max_eec1_electronic_engine_control_1_unpack,
        decode_dura_max_eec1_electronic_engine_control_1
    );
    counter++;

    handler.add_pgn_owner<dura_max_eec2_electronic_engine_control_2_t>(
        DURA_MAX_EEC2_ELECTRONIC_ENGINE_CONTROL_2_FRAME_ID,
        dura_max_eec2_electronic_engine_control_2_init,
        dura_max_eec2_electronic_engine_control_2_unpack,
        decode_dura_max_eec2_electronic_engine_control_2
    );
    counter++;

    handler.add_pgn_owner<dura_max_eec3_electronic_engine_control_3_t>(
        DURA_MAX_EEC3_ELECTRONIC_ENGINE_CONTROL_3_FRAME_ID,
        dura_max_eec3_electronic_engine_control_3_init,
        dura_max_eec3_electronic_engine_control_3_unpack,
        decode_dura_max_eec3_electronic_engine_control_3
    );
    counter++;

    handler.add_pgn_owner<dura_max_eec9_electronic_engine_control_9_t>(
        DURA_MAX_EEC9_ELECTRONIC_ENGINE_CONTROL_9_FRAME_ID,
        dura_max_eec9_electronic_engine_control_9_init,
        dura_max_eec9_electronic_engine_control_9_unpack,
        decode_dura_max_eec9_electronic_engine_control_9
    );
    counter++;

    handler.add_pgn_owner<dura_max_eec20_electronic_engine_control__t>(
        DURA_MAX_EEC20_ELECTRONIC_ENGINE_CONTROL__FRAME_ID,
        dura_max_eec20_electronic_engine_control__init,
        dura_max_eec20_electronic_engine_control__unpack,
        decode_dura_max_eec20_electronic_engine_control_
    );
    counter++;

    handler.add_pgn_owner<dura_max_cac1_charge_air_cooler_1_t>(
        DURA_MAX_CAC1_CHARGE_AIR_COOLER_1_FRAME_ID,
        dura_max_cac1_charge_air_cooler_1_init,
        dura_max_cac1_charge_air_cooler_1_unpack,
        decode_dura_max_cac1_charge_air_cooler_1
    );
    counter++;

    handler.add_pgn_owner<dura_max_easi_engine_air_system_info_t>(
        DURA_MAX_EASI_ENGINE_AIR_SYSTEM_INFO_FRAME_ID,
        dura_max_easi_engine_air_system_info_init,
        dura_max_easi_engine_air_system_info_unpack,
        decode_dura_max_easi_engine_air_system_info
    );
    counter++;

    handler.add_pgn_owner<dura_max_ebcc_engine_exhaust_brake_cont_t>(
        DURA_MAX_EBCC_ENGINE_EXHAUST_BRAKE_CONT_FRAME_ID,
        dura_max_ebcc_engine_exhaust_brake_cont_init,
        dura_max_ebcc_engine_exhaust_brake_cont_unpack,
        decode_dura_max_ebcc_engine_exhaust_brake_cont
    );
    counter++;

    handler.add_pgn_owner<dura_max_efl_p1_eng_fluid_level_press_1_t>(
        DURA_MAX_EFL_P1_ENG_FLUID_LEVEL_PRESS_1_FRAME_ID,
        dura_max_efl_p1_eng_fluid_level_press_1_init,
        dura_max_efl_p1_eng_fluid_level_press_1_unpack,
        decode_dura_max_efl_p1_eng_fluid_level_press_1
    );
    counter++;

    handler.add_pgn_owner<dura_max_efl_p2_eng_fluid_level_press_2_t>(
        DURA_MAX_EFL_P2_ENG_FLUID_LEVEL_PRESS_2_FRAME_ID,
        dura_max_efl_p2_eng_fluid_level_press_2_init,
        dura_max_efl_p2_eng_fluid_level_press_2_unpack,
        decode_dura_max_efl_p2_eng_fluid_level_press_2
    );
    counter++;

    handler.add_pgn_owner<dura_max_et1_engine_temperature_1_t>(
        DURA_MAX_ET1_ENGINE_TEMPERATURE_1_FRAME_ID,
        dura_max_et1_engine_temperature_1_init,
        dura_max_et1_engine_temperature_1_unpack,
        decode_dura_max_et1_engine_temperature_1
    );
    counter++;

    handler.add_pgn_owner<dura_max_et3_engine_temperature_3_t>(
        DURA_MAX_ET3_ENGINE_TEMPERATURE_3_FRAME_ID,
        dura_max_et3_engine_temperature_3_init,
        dura_max_et3_engine_temperature_3_unpack,
        decode_dura_max_et3_engine_temperature_3
    );
    counter++;

    handler.add_pgn_owner<dura_max_ic1_intake_exhaust_cond_1_t>(
        DURA_MAX_IC1_INTAKE_EXHAUST_COND_1_FRAME_ID,
        dura_max_ic1_intake_exhaust_cond_1_init,
        dura_max_ic1_intake_exhaust_cond_1_unpack,
        decode_dura_max_ic1_intake_exhaust_cond_1
    );
    counter++;

    handler.add_pgn_owner<dura_max_lfe1_fuel_economy_liquid_1_t>(
        DURA_MAX_LFE1_FUEL_ECONOMY_LIQUID_1_FRAME_ID,
        dura_max_lfe1_fuel_economy_liquid_1_init,
        dura_max_lfe1_fuel_economy_liquid_1_unpack,
        decode_dura_max_lfe1_fuel_economy_liquid_1
    );
    counter++;

    handler.add_pgn_owner<dura_max_tci5_turbocharger_information_5_t>(
        DURA_MAX_TCI5_TURBOCHARGER_INFORMATION_5_FRAME_ID,
        dura_max_tci5_turbocharger_information_5_init,
        dura_max_tci5_turbocharger_information_5_unpack,
        decode_dura_max_tci5_turbocharger_information_5
    );
    counter++;

    handler.add_pgn_owner<dura_max_vep1_vehicle_electrical_power_1_t>(
        DURA_MAX_VEP1_VEHICLE_ELECTRICAL_POWER_1_FRAME_ID,
        dura_max_vep1_vehicle_electrical_power_1_init,
        dura_max_vep1_vehicle_electrical_power_1_unpack,
        decode_dura_max_vep1_vehicle_electrical_power_1
    );
    counter++;

    std::cout << "\n" << "amount counter: " << counter << "\n";
}

