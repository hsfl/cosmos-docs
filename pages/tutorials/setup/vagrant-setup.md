---
title: "Setting up the Development Environment"
layout: page
permalink: /pages/tutorials/setup/setup-dev-env.html

tags: [software]
keywords: software
sidebar: home_sidebar
toc: false
---

## Brief

The Artemis Development Environment is provided as an Ubuntu 18.04.4 image with necessary tools preinstalled.

VirtualBox and Vagrant are used to ensure the development environment is cross-platform. VirtualBox is used for
virtualization of operating systems, and Vagrant is used to set up the virtual machine in a mostly
platform-independent manner.

### Why Linux?

Linux makes working with the kit software much easier, as the operating system as a whole is designed for developers.
It is also fairly lightweight, meaning that unnecessary add-ons are stripped away so that the download size is
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

```
vagrant plugin install vagrant-vbguest
```

## 2. Set up the Artemis Box

### 2.1 Add the Box

Download the Vagrant box (artemis.box). From a command prompt or terminal window, enter the following (using the path you downloaded the Vagrant box to):

```
cd PATH/TO/VAGRANT/BOX
vagrant box add artemis artemis.box
```

You can delete the `artemis.box` file you downloaded if you wish.

### 2.2 Create the Virtual Machine
Next, enter the following (replacing `PATH/TO/VM` with the folder you chose):

```
cd PATH/TO/VM
vagrant init artemis
```

Download the `Vagrantfile` file to the same folder, overwriting the file created by the `vagrant init artemis` command.
The new Vagrantfile will set up the virtual machine with necessary virtualization settings.

### 2.3 Start the Virtual Machine

Next run the command:

```
vagrant up
```

After a minute or so you should see the virtual machine boot. The default password is `vagrant`.

    username: vagrant
    password: vagrant

In the future you should be able to start the virtual machine directly from the VirtualBox GUI.

## 3. Update Software

{% include tip.html content="This step is optional. Follow this step if you want to make sure you have the
latest software." %}

From the virtual machine, open a new terminal (<kbd>Control</kbd> + <kbd>Alt</kbd> + <kbd>T</kbd>) and run the following command:


```bash
$ ./update
```

You will be prompted whether or not you want to update various components. Entering `y` will overwrite the existing
installations.

