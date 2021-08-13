---
title: Setup SLIP between two linux computers 
permalink: /pages/4-tutorials/hardware/setup-slip.html
layout: page

tags: [slip]
keywords: slip

---

Serial Line Internet Protocol or SLIP is a protocol that enables internet like calls over a serial connection (ex: UART, RS232, RS422). 
This tutorial assumes you have two Raspberry Pi's (RPI-1, RPI-2). 
The csmos_slip library lets you use SLIP protocol with IP packets. 
It is used be Cosmos_Serial library to support SLIP protocol over serial. 

Setting up a SLIP connection over Linux (though they do use the exact same protocol)
Just saying this because somewhere I was tasked with writing up a SLIP tutorial, and sliplib was mentioned, 
but now I think it was really SLIP over Linux. 🤯

Setting up slip on RPI-1
```
# enter this on /etc/network/interfaces
# SLIP configuration for RPI-1
auto sl0
iface sl0 inet static
  address 192.168.1.1
  netmask 255.255.255.0
  pointopoint 192.168.1.2
  pre-up slattach -s 115200 -p cslip -L /dev/ttyS2 &
  post-up route add 192.168.1.1 dev lo
```

Setting up slip on RPI-2
```
# enter this on /etc/network/interfaces
# SLIP configuration for RPI-2
auto sl0
iface sl0 inet static
  address 192.168.1.2
  netmask 255.255.255.0
  pointopoint 192.168.1.1
  pre-up slattach -s 115200 -p cslip -FL /dev/ttyS3 &
  post-up route add 192.168.1.2 dev lo
```


Other resources:
- [SLIP](https://en.wikipedia.org/wiki/Serial_Line_Internet_Protocol)
