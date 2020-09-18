---
title: "Setting up the Raspberry Pi From Scratch"
layout: page
permalink: /pages/tutorials/setup-from-scratch/raspi-from-scratch.html

tags: [software]
keywords: software
---

{% assign warning = "Before getting started, make sure to review the [safety procedures](" | append: 
site.baseurl | append: "/pages/safety-procedures.html#raspberry-pi) for working with the Raspberry Pi." %}
{% include important.html content=warning %}

## Enable SSH Over USB

SSH is required in order to remotely connect to the Raspberry Pi.

To set up the Raspberry Pi Zero (in headless mode) for SSH over USB, follow the instructions [here](https://desertbot.io/blog/ssh-into-pi-zero-over-usb). Connect the USB port on the Raspberry Pi to the USB Host port on the BeagleBone. From there, you should be able to SSH into the Raspberry Pi from the BeagleBone using the command below. The default password is `raspberry`.

```bash
$ ssh pi@raspberrypi.local
```

Next, we would like to be able to SSH into the Raspberry Pi without needing to enter the password every time. Open up a terminal on the BeagleBone and enter ssh-keygen to generate a new key pair. Leave the first field blank (just hit enter), and optionally enter a password for the following field. Now enter the command ssh-copy-id pi@raspberrypi.local to copy the public key over to the Raspberry Pi. You can make sure that the process was successful by entering:

```bash
ssh pi@raspberrypi.local
```

If you receive a password prompt, the process did not work. See the page [here](https://www.raspberrypi.org/documentation/remote-access/ssh/passwordless.md) for more details. The same process can be performed to allow the Raspberry Pi to SSH into the BeagleBone without encountering a password prompt.

Since logging with SSH will be fairly slow, we can speed it up by disabling DNS. Open up either `/etc/ssh/sshd_config` or `/etc/sshd_config` and change the line starting with `UseDNS` to `UseDNS no`. Upon reboot, this should drastically decrease the login time for the client calling SSH. This can be performed on both the Raspberry Pi and the BeagleBone.

## Connecting to the Internet Over USB
{% include note.html content="This has not yet been successfully performed with either the BeagleBone or a Windows machine as the host. It seems to be easiest to use a Mac computer." %}

### Internet Sharing on a Mac
Once the Raspberry Pi is set up, plug it into a Mac computer. Navigate to the Network pane in System Preferences, and you should see `RNDIS/Ethernet Gadget` pop up on the left. If you do not see this, there is probably something wrong. For more information on setting up internet sharing, visit [this article](https://solarianprogrammer.com/2018/12/07/raspberry-pi-zero-internet-usb/).

Next, go back and navigate to the Sharing pane and enable Internet Sharing to the `RNDIS/Ethernet Gadget`.

An internet connection is necessary for downloading packages, including the PiCamera Python module. To test whether your connection is working, you can try pinging a website:

```bash
$ ping google.com
```

## PiCamera Module Setup
You will need to install the PiCamera module in order to operate the camera from Python. Make sure you have an internet connection before proceding.

First, SSH into the Raspberry Pi from your host computer and run the following:

```bash
$ sudo apt-get update
$ sudo apt-get install python-picamera python3-picamera
```

It’s as easy as that! For further details, visit the [PiCamera installation guide]*https://picamera.readthedocs.io/en/release-1.13/install.html).


## Camera Setup

{% include warning.html content="Always make sure to power off the Raspberry Pi before changing any connections!" %}

Physically connecting the Raspberry Pi Camera Module is straightforward: release the clip on the CSI port located on the side of the board opposite the micro SD card slot, plug in the ribbon cable to the port (ensuring that the metal contacts are face-down on the board), and snap the CSI clip back into place.

Once the camera is connected, you can test it out by running the following command in a terminal on the Raspberry Pi (or through SSH). The image will be saved in a file called `image.jpg` in the current working directory.

```bash
$ raspistill -o ~/image.jpg
```
