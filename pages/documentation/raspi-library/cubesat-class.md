---
title: CubeSat Class (Raspberry Pi)
permalink: /pages/documentation/raspi-library/cubesat-class.html
layout: class

keywords: python, library

obc: raspi
class_name: cubesat
---

## Description

The CubeSat class is a container of Python objects needed to communicate with various components of the CubeSat
from the Raspberry Pi

## Usage

An instance of the CubeSat class is created when the `artemis` module is first imported. In a payload script, this
can be done using the following import statement:

```python
from artemis import cubesat
```

All necessary functionality is contained within the `cubesat` instance.

### Example 1

To update the `cubesat` object, you can execute the `update` function:

```python
cubesat.update()
```

### Example 2

To get the acceleration vector from the IMU:

```python
accel = cubesat.imu.acceleration

accel_x = accel[0]
accel_y = accel[1]
accel_z = accel[2]
```
