---
title: GPIO (Class)
permalink: /pages/documentation/utility-classes/gpio.html
layout: class

tags: [software]
keywords: software

class_name: gpio
---


## How Does it Work?

The GPIO pins on the BeagleBone can be controlled through special files located in the 
`/sys/class/gpio` folder. This folder contains a bunch of subdirectories, each one referring to a single GPIO pin. Rather than using names such as `P9_14`, the folders are named according to each pin's _absolute_ number. You can check the BeagleBone manual for a table of absolute pin numbers.

### Setting the Direction
To set the direction (input or output) of the pin, you can write to the GPIO pin's `direction` file:
* To set the pin as output: `echo out > direction`
* To set the pin as input: `echo in > direction`

### Setting the Value
To set the value of the pin during output mode, you can write to the pin's `value` file:
* To set the output to LOW: `echo 0 > value`
* To set the output to HIGH: `echo 1 > value`

### Getting the Value
To read the value of the pin, you can read from the pin's `value` file:
* To set the output to LOW: `cat value`
* To set the output to HIGH: `cat value`

### Exporting Pins
If the necessary pin is not available in the gpio folder, you may be able to enable it by writing the pin number to the `export` file. After you are done, you should unexport the pin by writing the pin number to the `unexport` file.

