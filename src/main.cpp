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

    {
        .signal_name = "remote_accel_pedal_pos",
        .subscriber_id = 0x300,
        .length = 8,
        .value = 0,
        .pos = 2,
        .scale = 0.00392156862745, 
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
        .pos = 6,
        .scale = 0.1, // mPa to Bar
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
        .scale = 4.00001,
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
        .scale = 0.62745098039, // degC, so (degC -> degF -> raw) -> raw = (degC +10) / 0.62712
        .offset = -10
    },
    Subscription{
        .signal_name = "eng_oil_temp1", //farenheit
        .subscriber_id = 0x30B,
        .length = 16,
        .value = 0,
        .pos = 1,
        .scale = 1, // put 1.8
        .offset = 0 // put -32 
    },
    // Subscription{
    //     .signal_name = "eng_fuel_temp1",
    //     .subscriber_id = 0x30B,
    //     .length = 8,
    //     .value = 0,
    //     .pos = 1,
    //     .scale = 1,
    //     .offset = 0
    // },
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
    Subscription{
        .signal_name = "eng_exhaust_gas_temp",
        .subscriber_id = 0x30B,
        .length = 16,
        .value = 0,
        .pos = 6,
        .scale = 1, // put 1.8
        .offset = 0, // put -32 before
    }

};

std::vector<Subscription> lfe1_subs = {};

std::vector<Subscription> tci5_subs = {};

std::vector<Subscription> vep1_subs = {
    {
        .signal_name  = "keyswitch_battery_potential_158", // value in V
        .subscriber_id = 0x308,
        .length       = 16,
        .pos          = 0,               // Bytes 0-1
        .scale        = 0.017595307918,  // V/bit  (DBC factor)
        .offset       = 0
    },
};



std::vector<Subscription> throttle_subs = {
    Subscription{
        .signal_name = "control_mode",
        .subscriber_id = DURA_MAX_TSC1_31_FRAME_ID,
        .length = 8,
        .value = 0,
        .pos = 0,
        .scale = 1,
        .offset = 0
    },
    Subscription{
        .signal_name = "speed_high",
        .subscriber_id = DURA_MAX_TSC1_31_FRAME_ID,
        .length = 8,
        .value = 0,
        .pos = 2,
        .scale = 1,
        .offset = 0
    },
    Subscription{
        .signal_name = "speed_low",
        .subscriber_id = DURA_MAX_TSC1_31_FRAME_ID,
        .length = 8,
        .value = 0,
        .pos = 1, // changed to .pos = 1 ( was .pos = 2)
        .scale = 1,
        .offset = 0
    },
    Subscription{
        .signal_name = "ff",
        .subscriber_id = DURA_MAX_TSC1_31_FRAME_ID,
        .length = 8,
        .value = 0,
        .pos = 3,
        .scale = 1,
        .offset = 0
    },
    Subscription{
        .signal_name = "ff",
        .subscriber_id = DURA_MAX_TSC1_31_FRAME_ID,
        .length = 8,
        .value = 0,
        .pos = 4,
        .scale = 1,
        .offset = 0        
    },
    Subscription{
        .signal_name = "ff",
        .subscriber_id = DURA_MAX_TSC1_31_FRAME_ID,
        .length = 8,
        .value = 0,
        .pos = 5,
        .scale = 1,
        .offset = 0
    },
    Subscription{
        .signal_name = "ff",
        .subscriber_id = DURA_MAX_TSC1_31_FRAME_ID,
        .length = 8,
        .value = 0,
        .pos = 6,
        .scale = 1,
        .offset = 0
    },
    Subscription{
        .signal_name = "arc", // this is also the checksum here
        .subscriber_id = DURA_MAX_TSC1_31_FRAME_ID,
        .length = 8,
        .value = 0,
        .pos = 7,
        .scale = 1,
        .offset = 0
    },

};


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
    handler.set_outgoing_message(DURA_MAX_TSC1_31_FRAME_ID,{});

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
                    if(message.can_id == DURA_MAX_TSC1_31_FRAME_ID){
                        frame.can_id = 0xC000031 | CAN_EFF_FLAG;  // Set extended CAN ID
                    }
                    else{
                        frame.can_id = message.can_id;
                    }
                    
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
    handler.set_subscriptions(0x200, throttle_subs);

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

    handler.add_pgn_owner<canopen_throttle>(
        0x200,
        // init
        [](canopen_throttle* strct)->int{ 
            strct = {0};
            return 1;
        },
        // unpack 
        [](canopen_throttle* strct, const uint8_t *data, size_t size){ 
            strct->control_mode = data[4];
            strct->speed_low = data[5];
            strct->speed_high = data[6];
            strct->arc = data[7]; // arc and checksum
        },
        // decode
        [](std::unordered_map<std::string, double>& value_map, canopen_throttle* strct){
          static uint8_t alive_rolling_counter = 0;

            // so until we reach 5 %  send the control mode as 00
            uint16_t speed_value = (strct->speed_high << 8 ) | strct->speed_low;
            speed_value = ( (speed_value > 10400) ? (speed_value > 16008) ? speed_value : 16000 : 10000 );
            strct->speed_high = (speed_value >> 8) & 0xff;
            strct->speed_low = speed_value & 0xff; 
            double rpm_ = speed_value * 0.125;
            
            value_map["control_mode"] = (strct->speed_high < 0x21)? 0x00 : 0xF1;
            
          
            value_map["speed_high"] = strct->speed_high;
            value_map["speed_low"] = strct->speed_low;
            

            // THE GOAL!
            //value_map["arc"] = ;
            
            
            uint8_t fake_data[8] = {
                value_map["control_mode"], // control mode
                strct->speed_low & 0xff, // low_bytes of throttle
                strct->speed_high & 0xff, // high_bytes of throttle
                0xff,
                0xff,
                0xff,
                0xff,
                0xff  // checksum (higher nibble) | arc (lower nibble)
            };
            
            
            
          
            auto calc_checksum = [](uint32_t id, const uint8_t* data, uint8_t arc){                        
              uint32_t VeGMDR_y_Sum = 0x00;
              uint8_t VeGMDR_y_ChkSm = 0x00;
              
              // Sum up the first 7 bytes of the message
              for (int i = 0; i < 7; i++) {
                  VeGMDR_y_Sum += data[i];
              }

              // Add ARC (lower 4 bits), and each byte of the ID
              VeGMDR_y_Sum += (arc & 0x0F);
              VeGMDR_y_Sum += (uint8_t)(id);
              VeGMDR_y_Sum += (uint8_t)(id >> 8);
              VeGMDR_y_Sum += (uint8_t)(id >> 16);
              VeGMDR_y_Sum += (uint8_t)(id >> 24);

              // Compute checksum (3 bits)
              VeGMDR_y_ChkSm = ((((VeGMDR_y_Sum >> 6) & 0x03) + (VeGMDR_y_Sum >> 3) + VeGMDR_y_Sum) & 0x07);

              return VeGMDR_y_ChkSm;
            };
            
            auto combine_arc_checksum = [](uint8_t arc, uint8_t checksum){
                return ((checksum & 0x0f) << 4) | (arc & 0x0F); // Upper 4 bits: checksum, lower 4 bits: ARC
            };
            
            uint8_t checksum = calc_checksum(0xC000031, fake_data, alive_rolling_counter);
            value_map["arc"] = combine_arc_checksum(alive_rolling_counter, checksum);
            alive_rolling_counter = (alive_rolling_counter + 1) % 8;
            
            /*
# === Utility Functions ===
def calculate_checksum(can_id, data, arc):
    checksum_sum = sum(data[:7])
    checksum_sum += arc & 0x0F
    checksum_sum += (can_id & 0xFF)
    checksum_sum += ((can_id >> 8) & 0xFF)
    checksum_sum += ((can_id >> 16) & 0xFF)
    checksum_sum += ((can_id >> 24) & 0xFF)
    checksum = (((checksum_sum >> 6) & 0x03) + (checksum_sum >> 3) + checksum_sum) & 0x07
    return checksum

def pack_checksum_and_arc(arc, checksum):
    return ((checksum & 0x0F) << 4) | (arc & 0x0F)
*/


        }

    );
    

    std::cout << "\n" << "amount counter: " << counter << "\n";
}

