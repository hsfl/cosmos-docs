---
title: "Getting Started Part 4 - Camera Script"
layout: series
permalink: /pages/tutorials/setup/setup4.html

tags: [software]
keywords: software
sidebar: home_sidebar
toc: false

series:
  prev: /pages/tutorials/setup/setup3.html
---



## 1. SSH into the Raspberry Pi

From the Cloud9 IDE, enter the following command into a terminal and enter the password when prompted (default is `raspberrypi`):

```bash
$ ssh pi@raspberrypi.local
```

This will allow you to run shell commands on the Raspberry Pi.


## 2. Start the Camera Script

There is a camera script included on the Raspberry Pi out-of box. To run the script, enter the following command:

```bash
$ python ~/scripts/camera.py
```

## 3. Check the Output

The script should periodically capture images to the `~/payload_files` folder. Enter the following command a couple times (waiting ten seconds or so between them) to list the captured imges:

```bash
$ ls ~/payload_files
```

Although the images can't be viewed in headless mode, the camera script also copies the images to the BeagleBone under
the folder `/home/debian/raspi/incoming/`. You can browse this folder using the navigation bar on the left of the
Cloud9 IDE. Double-click on one of the images to see it!