#!/bin/bash
INTERFACE=$1 #interface is passed in, and the script searches for its inet IP address and pings it

echo -e "Current host is:\t$HOSTNAME"

myInet=$(ifconfig $INTERFACE inet | tail -n 1)
[[ $myInet =~ inet(.*)netmask ]]
IP=${BASH_REMATCH[1]}
echo -e "Bash rematch is:\t${BASH_REMATCH[0]}"
echo -e "Bash rematch [2] is:\t$IP"

echo Pinging current IP address
echo "$IP is the current IP"
eval ping -c 5 $IP













