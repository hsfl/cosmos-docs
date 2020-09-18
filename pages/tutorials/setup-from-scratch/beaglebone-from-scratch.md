---
title: "Setting up the BeagleBone From Scratch"
layout: page
permalink: /pages/tutorials/setup-from-scratch/beaglebone-from-scratch.html

tags: [software]
keywords: software
---

{% assign warning = "Before getting started, make sure to review the [safety procedures](" | append: 
site.baseurl | append: "/pages/safety-procedures.html#beaglebone) for working with the BeagleBone." %}
{% include important.html content=warning %}

## What You'll Need
* BeagleBone Black
  * Micro SD Card (this will be overwritten)
* Desktop computer
  * Internet Connection
  * A way of writing to the Micro SD Card (built-in slot, external writer, SD card adapter, etc.)
* Ethernet Cable (optional, for updating )
* USB Type A to USB Mini B cable

## Set Up the Debian Image
The steps for setting up the Debian image on the BeagleBone are located on the [BeagleBoard website](https://beagleboard.org/getting-started).



## Make Sure It's Working
Connect the BeagleBone to your computer using a micro-USB cable inserted into the port labeled “USB” on the board. After a little while, the BeagleBone should show up as a device on your computer. If you are using a Windows host machine, you may need to eject this device before proceeding.

Open up a web browser and navigate to:


* **Windows:** http://192.168.7.2/
* **Linux/Mac:** http://192.168.6.2/

 You may need to wait a minute if the BeagleBone is still booting. Eventually you should see the Cloud9 IDE.


## Set up COSMOS on the BeagleBone
For setting up COSMOS on the BeagleBone, visit the [Installing COSMOS From Scratch](cosmos-from-scratch.html) page.