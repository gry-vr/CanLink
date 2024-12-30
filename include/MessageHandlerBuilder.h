#pragma once

#include "PGN_Owner.h"
#include "MessageHandler.h"
#include "util.h"

// Forward declaration of MessageHandler
template <typename StructType>
class MessageHandler; 

template <typename StructType>
class MessageHandlerBuilder {
private:
    // Temp storage for building
    std::unordered_map<int, PGN_Owner<StructType>> id_to_owner_;
    std::unordered_map<int, std::vector<Subscription>> id_to_subscriptions_;
    std::unordered_map<int, CANOpenMessage> id_to_outgoing_;
    std::unordered_map<int, bool> updated_ids_;

public:
    MessageHandlerBuilder() = default;

    // Register a PGN_Owner for a particular incoming CAN ID
    // so we know how to decode that message.
    MessageHandlerBuilder& registerPgnOwner(int incomingId, const PGN_Owner<StructType>& pgnOwner)
    {
        //id_to_owner_[incomingId] = pgnOwner;
        id_to_owner_.insert_or_assign(incomingId, pgnOwner);
        return *this;
    }

    // Add a (incomingId -> outgoingId) subscription with a given Subscription
    MessageHandlerBuilder& addMessageHandling(
        int incomingId,
        int outgoingId,
        const Subscription& subscription
    ) {
        // Associate subscription with the incoming ID
        id_to_subscriptions_[incomingId].push_back(subscription);
        
        // Ensure there's a CANOpenMessage for the outgoing ID
        auto& outMsg = id_to_outgoing_[outgoingId];
        outMsg.can_id = outgoingId;   // set the CAN ID
        outMsg.length = 8;           // typically 8 for CAN frames

        // Mark it initially as "not updated"
        updated_ids_[outgoingId] = false;

        return *this;
    }

    // Finally, build the MessageHandler
    MessageHandler<StructType> build()
    {
        return MessageHandler<StructType>(
            std::move(id_to_owner_),
            std::move(id_to_subscriptions_),
            std::move(id_to_outgoing_),
            std::move(updated_ids_)
        );
    }
};
