---
title: Reading Data from an Arduino
permalink: /pages/4-tutorials/agents-with-hardware/arduino.html
layout: page
index: 4.7.1
tags: [software]
keywords: software
---
[Reading Data from an Arduino](https://docs.google.com/document/d/1nrOId7-6iBiTzjoFnFobEZpwlmBhdKSEu3mWkHiQ094/edit#heading=h.yi6izp7x6ipy)

[Reading data from 2 different Agents (arduino & teensy)](https://docs.google.com/document/d/1nrOId7-6iBiTzjoFnFobEZpwlmBhdKSEu3mWkHiQ094/edit#heading=h.w0pqw83bdzwg)

[Xbee communication over serial port](https://docs.google.com/document/d/1nrOId7-6iBiTzjoFnFobEZpwlmBhdKSEu3mWkHiQ094/edit#heading=h.jnyw5y84y1i)

(incomplete)
In this tutorial we’ll be measuring temperature and humidity data from the [DHT11](https://www.adafruit.com/product/386) sensor and plotting the real-time data using CosmosPlot. [The sensor is connected to the Arduino](https://learn.adafruit.com/dht) which in turn is connected to a computer that can read a serial port (USB to Serial). 

**Note: There are 2 Arduino IDEs - online IDE and offline (Desktop IDE).

1.Download the Arduino IDE appropriate for your OS from here: 
   
   [https://www.arduino.cc/en/Main/Software](https://www.arduino.cc/en/Main/Software)
   
   a. Extract and install the archive. Follow the instructions linked here: 
       [https://www.arduino.cc/en/Guide/Linux#toc3](https://www.arduino.cc/en/Guide/Linux#toc3)
   
   b. If the resulting executable is not named “Arduino IDE”, right click on the file and under Properties>Permissions, 
       check the box that allows the file to be executed as a program.
   
   c. Setup the Arduino IDE for your board.

2. Clone the COSMOS Arduino repository from [https://bitbucket.org/cosmos-project/cosmos-arduino](https://bitbucket.org/cosmos-project/cosmos-arduino)
   to the folder <cosmos>/source/projects/cosmos-arduino
      
  a. Useful files:
      
     1. (arduino_code.ino) Template program for the Arduino that sends data on the serial port in JSON format

     2. (agent_arduino.cpp) Use this as a template to make an agent for the arduino

     3. (plot-arduino.json) Configuration file for CosmosPlot 
  
 3. Create Node or clone node-arduino
  
   a. Create Node 
  
       1. Use DMT to create new node (follow this tutorial to install/compile DMT)

       2. Node information must match the sensor information
          


  
