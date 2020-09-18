---
title: Uploading the Script
permalink: /pages/tutorials/scripts/scripts2.html
layout: series


tags: [software, payload, scripts, camera]
keywords: software, payload, scripts, camera
toc: false

series:
    prev: /pages/tutorials/scripts/scripts1.html
    next: /pages/tutorials/scripts/scripts3.html
---

## Copy to the BeagleBone

Now that you've written a payload script, it's time to transfer it to the Raspberry Pi.

First, copy the `~/scripts` folder to the BeagleBone:


```bash
$ rsync -auv ~/scripts debian@beaglebone.local:/home/debian/
```

The `scripts` folder will end up in the BeagleBone home directory.

For the next step, open up a terminal in Cloud9.

## Copy to the Raspberry Pi

Now run the following command:

```bash
$ rsync -auv ~/scripts pi@raspberrypi.local:/home/pi
```

The `scripts` folder will end up the Raspberry Pi home directory.