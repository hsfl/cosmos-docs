---
title: Safety Procedures
permalink: /pages/safety-procedures.html
layout: page

keywords: safety
---

## General Procedures

### Electrostatic Discharge
When working with electrical components, it is best to place them atop an ESD protective mat
and wear an antistatic wrist strap.

When transporting ESD-sensitive components you should place them in antistatic bags.



## Raspberry Pi

### Turning it Off

Before disconnecting power to the Raspberry Pi, you should shut it down as you would with a normal computer.


To shut down the Raspberry Pi from the BeagleBone, run the following in a Cloud9 terminal (or in a regular terminal
if the Raspberry Pi is connected directly to your computer):

```bash
$ ssh pi@raspberrypi.local sudo shutdown now
```

Once all the lights on the board have turned off, it is safe to disconnect power.

{% include warning.html content="Failure to do this could result in loss of data or corruption of the SD card." %}



## BeagleBone

### Changing Connections

Before modifying any connections to the BeagleBone, you should make sure the board is [powered off](#turning-it-off-1)
and unplugged.

{% include warning.html content="Failure to do this could result in permanent damage to the power lines." %}


### Turning it Off

Before disconnecting power to the BeagleBone, you should shut it down as you would with a normal computer.


To shut down the BeagleBone, run the following code in a Cloud9 terminal window:

```bash
$ sudo shutdown now
```

Once all the lights on the board have turned off, it is safe to disconnect power.


{% include warning.html content="Failure to do this could result in loss of data or corruption of the SD card." %}