// PGN_Owner_Wrapper.h
#pragma once
#include "PGN_Owner_Base.h"
#include <functional>

template <typename StructType>
class PGN_Owner_Wrapper : public PGN_Owner_Base {
private:
    StructType strct;
    std::function<void(StructType*, const uint8_t*, size_t)> unpack_func;
    std::function<void(std::unordered_map<std::string, double>&, StructType*)> decode_func;

public:
    // Constructor for decode-only PGN owners
    PGN_Owner_Wrapper(
        StructType strct_in,
        std::function<void(std::unordered_map<std::string, double>&, StructType*)> decode_func_in
    ) : strct(strct_in), decode_func(decode_func_in) {}

    // Constructor for full-featured PGN owners
    PGN_Owner_Wrapper(
        std::function<int(StructType*)> init_func,
        std::function<void(StructType*, const uint8_t*, size_t)> unpack_func_in,
        std::function<void(std::unordered_map<std::string, double>&, StructType*)> decode_func_in
    ) : unpack_func(unpack_func_in), decode_func(decode_func_in) {
        init_func(&strct);
    }

    void update_values(const uint8_t* data) override {
        if (unpack_func) {
            unpack_func(&strct, data, 8);
        }
    }

    void add_to_valuetable(std::unordered_map<std::string, double>& value_map) override {
        decode_func(value_map, &strct);
    }
};