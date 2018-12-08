ifconfig -a link | grep ether | tr -d '\t' | cut -c 7-23
