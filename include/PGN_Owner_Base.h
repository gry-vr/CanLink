// PGN_Owner_Base.h
#pragma once
#include <unordered_map>
#include <string>
#include <cstdint>
#include <iostream>


class PGN_Owner_Base {
public:
    virtual ~PGN_Owner_Base() = default;
    virtual void update_values(const uint8_t* data) = 0;
    virtual void add_to_valuetable(std::unordered_map<std::string, double>& value_map) = 0;
};