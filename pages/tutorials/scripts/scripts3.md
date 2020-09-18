---
title: Running the Script
permalink: /pages/tutorials/scripts/scripts3.html
layout: series

tags: [software, payload, scripts, camera]
keywords: software, payload, scripts, camera
toc: false

series:
    prev: /pages/tutorials/scripts/scripts2.html
---


## SSH into the Raspberry Pi

In a Cloud9 terminal, run the following:

```bash
$ ssh pi@raspberrypi.local
```

Enter the password when prompted (the default is `raspberrypi`). This will allow us to run commands on the Raspberry Pi.


## Run the Payload Script

Since the example script uses the folder `/home/pi/payload_files`, we should make the folder before running it:

```bash
$ mkdir ~/payload_files
```

Now run the script by entering the commands:

```
$ cd ~/scripts
$ python my_scripts.py
```

You should start seeing output from the script. All the pictures taken from the camera will end up in the
folder we previously created.

## Images on the BeagleBone

The cubesat library's `copy_to` function copies files to the `/home/debian/raspi/incoming/` folder on the BeagleBone
if no destination path is supplied (as in the example code). You can open up the `/home/debian/raspi` folder in the
navigation sidebar in Cloud9 to see the image files as the trickle in.