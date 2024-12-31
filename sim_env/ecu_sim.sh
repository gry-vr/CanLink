#! /bin/bash

#AMB message
cansend vcan1 18fdd500#8002000020003980

echo "sent amb"

#EEC1
cansend vcan1 0CF00400#DEADBEEF
echo "sent eec1"

#EEC5
cansend vcan1 18FEF500#DEADBEEF
echo "sent eec5"

#EEC9
cansend vcan1 10FCFD00#DEADBEEF
echo "sent eec9"

#EBCC
cansend vcan1 18FCE300#BEEFDEAD
echo "sent ebcc"


#EFC_p1
cansend vcan1 18FEEF00#DEADBEEF
echo "sent efc_p1"


#ET1
cansend vcan1 18FEEE00#DEADBEEF
echo "sent et1"

#IC1
cansend vcan1 18FEF600#DEADBEEF
echo "sent ic1"
