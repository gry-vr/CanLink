#pragma once
#include "PGN_Owner_Wrapper.h"
#include "util.h"
#include <memory>
#include <linux/can.h>


class MessageHandler {
private:
  std::unordered_map<std::string, double> value_map;
  std::unordered_map<uint32_t, std::unique_ptr<PGN_Owner_Base>> id_to_owner;
  std::unordered_map<uint32_t, std::vector<Subscription>> id_to_subscriptions;
  std::unordered_map<uint32_t, CANOpenMessage> id_to_outgoing;
  std::unordered_map<uint32_t, bool> updated_ids;

  void pack_all_outgoing(uint32_t id) {
      auto subs_it = id_to_subscriptions.find(id);
      if (subs_it == id_to_subscriptions.end()) return;

      std::cout << "PACKING OUTGOING \n";
      auto& subs = subs_it->second;
      std::cout << "size of subs " << subs.size() << "\n";

      for (auto& sub : subs) {

          auto outgoing_it = id_to_outgoing.find(sub.subscriber_id);
          if (outgoing_it != id_to_outgoing.end()) {
              pack_outgoing(sub, outgoing_it->second);
              std::cout << "WTF " << sub.subscriber_id << "\n";
              updated_ids[sub.subscriber_id] = true;
          }
      }
  }

  void pack_outgoing(Subscription& sub, CANOpenMessage& msg) {  // Removed const from Subscription
      auto it = value_map.find(sub.signal_name);
      if (it == value_map.end()) {
          std::cerr << "Signal " << sub.signal_name << " not found in value_map." << std::endl;
          return;
      }
      if( (sub.pos >= 7 && sub.length == 16) || (sub.pos > 7 && sub.length == 8) ){
          std::cerr << "There was an issue with the " << sub.signal_name << " subscription position or length \n";
          return;
      }

      msg.can_id = sub.subscriber_id;
      double value = (it->second - sub.offset) / sub.scale;

      if (sub.length == 8) {
          msg.data[sub.pos] = sub.return_8(static_cast<uint8_t>(value));
      } else if (sub.length == 16) {
          uint16_t packed_value = sub.return_16(static_cast<uint16_t>(value));
          msg.data[sub.pos + 1] = packed_value & 0xFF;
          msg.data[sub.pos] = (packed_value >> 8) & 0xFF;
      } else {
          std::cerr << "Unsupported signal length for signal: " << sub.signal_name << std::endl;
      }
  }

public:
  // Add a decode-only PGN owner
  template <typename StructType>
  void add_pgn_owner(
      int id,
      StructType strct,
      std::function<void(std::unordered_map<std::string, double>&, StructType*)> decode_func
  ) {
      id_to_owner[id] = std::make_unique<PGN_Owner_Wrapper<StructType>>(
          strct,
          decode_func
      );
  }

  // Add a full-featured PGN owner
  template <typename StructType>
  void add_pgn_owner(
      int id,
      std::function<int(StructType*)> init_func,
      std::function<void(StructType*, const uint8_t*, size_t)> unpack_func,
      std::function<void(std::unordered_map<std::string, double>&, StructType*)> decode_func
  ) {
      id_to_owner[id] = std::make_unique<PGN_Owner_Wrapper<StructType>>(
          init_func,
          unpack_func,
          decode_func
      );
  }

  void set_subscriptions(uint32_t id, std::vector<Subscription>& subs) {  // Removed const
      id_to_subscriptions[id] = subs;
  }

  void set_outgoing_message(uint32_t id, CANOpenMessage&& msg) {  // Removed const
      id_to_outgoing[id] = msg;
      updated_ids[id] = false;
  }


  void handleIncoming(const can_frame& msg) {
      uint32_t unmasked_id = msg.can_id & CAN_EFF_MASK;
      auto it = id_to_owner.find(unmasked_id);
      std::cout << "incoming ID " << unmasked_id <<"\n";

      if (it == id_to_owner.end()) return;

      std::cout << "MADE IT PAST \n";
      it->second->update_values(msg.data);
      it->second->add_to_valuetable(value_map);
      pack_all_outgoing(unmasked_id);
      print_update_id_map();
  }

  std::vector<CANOpenMessage> getAllOutgoingMessages() {
      std::vector<CANOpenMessage> result;
      std::cout << "Getting outgoing msgs\n";
      result.reserve(id_to_outgoing.size());

      for (auto& [id, msg] : id_to_outgoing) {
          std::cout << "ID " << id << "\n";
          if (updated_ids[id]) {
              
              std::cout << "WHYY ID " << id << "\n";
              result.push_back(msg);
              updated_ids[id] = false;
          }
      }

      std::cout << "SIZE: " << result.size() << "\n";

      return result;
  }

  void print_value_map(){
      for(const auto& [signal,value] : value_map){
          std::cout << "Signal " << signal << " value " << value << "\n";
      }
  }

  void print_update_id_map(){
      for(const auto& [id,val] : updated_ids){
          std::cout << "Signal " << id << " value " << val << "\n";
      }
  }
};
