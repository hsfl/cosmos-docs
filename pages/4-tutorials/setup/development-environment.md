---
title: "Getting Started Part 2 - Development Environment"
layout: series
permalink: /pages/4-tutorials/setup/development-environment.html

tags: [software]
keywords: software
sidebar: home_sidebar
toc: false


series:
  next: /pages/4-tutorials/setup/cosmos-web.html
---

## Introduction

The COSMOS Development Environment consists of Ubuntu 18.04.5. If you have MacOS or Windows OS, you can install
Oracle VM VirtualBox.

VirtualBox is used to virtualize operating systems, allowing users to simulate operating systems without installing
it on their hard drive.

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
VirtualBox is used to run the virtual machine used as the development environment. Get it [here](https://www.virtualbox.org/wiki/Downloads). Under VirtualBox
X.X.XX (6.1.14 at time of writing) Platform Packages, choose the installation of your native operating system.

Follow the installation wizard to complete the installation process.

### 1.2 Install Ubuntu 18.04 Image

The Ubuntu image version recommended for COSMOS is 18.04, and can be downloaded [here](https://releases.ubuntu.com/18.04/?_ga=2.103985858.339547959.1600722773-1484274794.1597110289). An image is a copy of the operating system, with all of the information, executables, and data files that it uses.

{% include important.html content="Download the `64-bit PC (AMD64) desktop image`, not the server image." %}

## 2. Set up the VirtualBox

After installing VirtualBox and the Ubuntu image, you can follow these [instructions](https://itsfoss.com/install-linux-in-virtualbox) to set up Ubuntu on VirtualBox. The instructions will be repeated below for convenience.

### 2.1 Start VirtualBox

Double-click the VirtualBox icon on your desktop, and then press _New_. Name your operating system and match the settings in the image below.

### 2.2 Allocate RAM

Choose how much memory you wish to provide to the operating system when it is running. It is recommended to allocate 1/3 - 1/4 of your maximum RAM. The more RAM you allocate, the faster your virtual operating system will be.

{% include tip.html content="It is recommended to allocate 1/3 - 1/4 your maximum RAM, but the more RAM you can allocate, the faster your virtual operating system will be." %}
{% include note.html content="1000 MB = 1 GB" %}

### 2.3 Hard Disk Setup

Create a virtual hard disk and choose VDI on the next two setup windows. In the following window, you can choose between _Dynamically allocated_ and _Fixed size_ to choose how much space on your hard disk the operating system takes up.

### 2.4 Hard Disk Size

You can now partition how much of your hard disk is used for the virtual operating system. It is recommended to have at least 10 GB worth of storage.

Now that you've successfully finished the setup, you can now proceed to install the image you downloaded earlier.

### 2.5 Boot ISO

Start the new operating system you created. The first time you start the system, it will ask you to select a start-up disk. Browse to where you installed the Ubuntu 18.04 iso file in the earlier step.

### 2.6 Install Ubuntu

When you run Ubuntu, it gives you the option to try it or install it. Press _Install Ubuntu_ and click _Continue_ on the next page.

Select _Erase disk and install Ubuntu_. Since this is being done on a virtual machine, it will not delete the operating system you have on your computer.

Proceed to complete the steps in the installation wizard.

Once the installation wizard is complete, you are ready to install COSMOS.
