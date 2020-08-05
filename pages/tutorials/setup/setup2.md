---
title: "Getting Started Part 2 - Development Environment"
layout: series
permalink: /pages/tutorials/setup/setup2.html

tags: [software]
keywords: software
sidebar: home_sidebar
toc: false


series:
  prev: /pages/tutorials/setup/setup1.html
  next: /pages/tutorials/setup/setup3.html
---

## Introduction

The Artemis Development Environment is provided as an Ubuntu 18.04.4 Vagrant box with necessary tools preinstalled.

VirtualBox and Vagrant are used to ensure the development environment is cross-platform. VirtualBox is used for
virtualization of operating systems, and Vagrant is used to set up the virtual machine in a (mostly)
platform-independent manner.

### Why Linux?

Linux makes working with the kit software much easier, as the operating system as a whole is designed for developers.
Our image is also fairly lightweight, meaning that unnecessary software is stripped out so that the download size is
minimal.

### Supported Operating Systems

The supported operating systems are essentially those that VirtualBox and Vagrant support:

* Windows
* macOS
* Linux



## 1. Install Dependencies

### 1.1 VirtualBox
VirtualBox is used to run the virtual machine used as the development environment. Get it [here](https://www.virtualbox.org/wiki/Downloads).


### 1.2 Install Vagrant

Vagrant is used to set up the virtual machine used as the development environment. Get it [here](https://www.vagrantup.com/downloads).

### 1.3 Install the Guest Additions Plugin

The Vagrant guest additions plugin automatically installs VirtualBox guest additions into the virtual machine. Install it
by opening up a command prompt (Windows) or a terminal (Linux/Mac) and running the following:

```bash
$ vagrant plugin install vagrant-vbguest
```

{% include important.html content="Do not copy the `$` character or the following space when entering commands.
This notation is used to indicate the input to a terminal." %}

## 2. Set up the Artemis Box

### 2.1 Add the Box

Download the Artemis box from
[here](https://drive.google.com/file/d/1DE3rlG3X5IrTut54pok7zP7xZzsjPFm_/view?usp=sharing).
From a command prompt or terminal window, enter the following command
using the path you downloaded the Vagrant box to. An example location on Windows is
`C:\Users\YOUR_USERNAME\Documents\Vagrant\artemis`.

```bash
$ cd PATH/TO/VAGRANT/BOX
$ vagrant box add artemis artemis.box
```

You can now delete the `artemis.box` file you downloaded if you wish.

### 2.2 Create the Virtual Machine

Enter the following commands, replacing `PATH/TO/VM` with the folder you chose.

```bash
$ cd PATH/TO/VM
$ vagrant init artemis
```

Download the `Vagrantfile` file from
[here](https://drive.google.com/file/d/101mCavBwqa-DI9gCteU7ywSimwF4yU0Z/view?usp=sharing)
and copy it to the folder you previously chose,
overwriting the existing `Vagrantfile` file.
The new Vagrantfile will set up the virtual machine with necessary virtualization settings.

### 2.3 Start the Virtual Machine

Next run the command:

```bash
$ vagrant up
```

After a minute or so you should see the virtual machine boot. The default password is `vagrant`.

Open a terminal inside the virtual machine (<kbd>Control</kbd> + <kbd>Alt</kbd> + <kbd>T</kbd> or the
black box icon on the dock) and enter the following command:

```bash
$ sudo apt install virtualbox-guest-dkms virtualbox-guest-utils virtualbox-guest-x11
```

{% include important.html content="Copying and pasting will not work until after this step, so make sure
you type this command exactly as it appears!" %}

### 2.4 Reboot the Virtual Machine

Reboot the machine by returning to your host terminal and entering:

```bash
$ vagrant halt
$ vagrant up
```

In the future you should be able to start the virtual machine directly from the VirtualBox GUI, or you can continue
running `vagrant up` in the virtual machine folder.

### 2.5 Enable Useful Features
Once you have logged into the `vagrant` user again (default password is `vagrant), you can enable some useful tools:

#### Automatic Display Resizing

This feature will resize the guest display when you adjust the size of the container window.

Click on the _View_ menu at the top of the virtual machine and click on `Auto-resize Guest Display`. If it is already
selected, then you should click on it again.

#### Shared Clipboard

This feature will allow you to copy and paste between the host and guest machines.

Click on the _Devices_ menu at the top of the virtual machine and click on _Shared Clipboard_ > _Bidirectional_.

{% include note.html content="When you paste text into a terminal you must use the
<kbd>Control</kbd> + <kbd>Shift</kbd> + <kbd>V</kbd> shortcut, and when you copy text from a terminal you must
use the <kbd>Control</kbd> + <kbd>Shift</kbd> + <kbd>C</kbd> shortcut." %}

## 3. Update Software

From the virtual machine, open a new terminal (<kbd>Control</kbd> + <kbd>Alt</kbd> + <kbd>T</kbd>) and run the following command:


```bash
$ ./update
```

You will be prompted whether or not you want to update various components. Entering `y` will overwrite the existing
installations, if present.



## Further Reading
* [Artemis Development Environment]({{site.folder_docs_other}}/development-environment.html)
