#!/bin/bash


modprobe vcan

if [ $? -eq 0 ]; then
    echo "successful modprobe"

    ip link add dev vcan0 type vcan
    ip link set vcan0 mtu 16

    ip link add dev vcan1 type vcan
    ip link set vcan1 mtu 16

    ip link set up vcan0 
    ip link set up vcan1

    echo "successful setup vcan0 and vcan1 ready for testing"

else
    echo "unsuccessful vcan kernel module not loaded"

fi



