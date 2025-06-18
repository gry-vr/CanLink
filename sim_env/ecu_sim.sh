#! /bin/bash

#AMB message
cansend vcan1 98fef500#DEADBEEFDEADBEEF
# placeholder value pls fix
echo "sent amb"

#EEC1
cansend vcan1 8cf00400#DEADBEEFDEADBEEF
echo "sent eec1"

#EEC9
cansend vcan1 90fcfd00#DEADBEEFDEADBEEF
echo "sent eec9"


#ET1
cansend vcan1 98feee00#53ADBEEFDEADBEEF
echo "sent et1"

#IC1
cansend vcan1 98fef600#DEADBEEFDEADBEEF
echo "sent ic1"

#EFl_P1
cansend vcan1 98feef00#DEADBEEFDEADBEEF
echo "sent efl_p1"

#VEP1
cansend vcan1 98fef700#DEADBEEFDEADF000
echo "sent vep1"


#EEC1
#cansend vcan1 0CF00400#DEADBEEF
#echo "sent eec1"

#EEC5
#cansend vcan1 18FEF500#DEADBEEF
#echo "sent eec5"

#EEC9
#cansend vcan1 10FCFD00#DEADBEEF
#echo "sent eec9"

#EBCC
#cansend vcan1 18FCE300#BEEFDEAD
#echo "sent ebcc"


#EFC_p1
#cansend vcan1 18FEEF00#DEADBEEF
#echo "sent efc_p1"


#ET1
#cansend vcan1 18FEEE00#DEADBEEF
#echo "sent et1"

#IC1
#cansend vcan1 18FEF600#DEADBEEF
#echo "sent ic1"
