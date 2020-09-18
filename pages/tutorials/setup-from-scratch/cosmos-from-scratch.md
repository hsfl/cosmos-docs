---
title: Installing COSMOS From Scratch
permalink: /pages/tutorials/setup-from-scratch/cosmos-from-scratch.html
layout: page

tags: [software]
keywords: software

---


## Introduction

If you want to install COSMOS without using the development environment, you can always install COSMOS from scratch.

{% include warning.html content="It is still _highly_ recommended that you install COSMOS on Ubuntu 18.04.3 for compatibility." %}

## Clone COSMOS Core

First you should make sure that you have all the dependencies you need by running the following in a terminal window:

```bash
$ sudo apt update && sudo apt upgrade -y
$ sudo apt-get install git cmake build-essential -y
```

Next, clone the installer script:

```bash
$ git clone https://bitbucket.org/cosmos-project/installer.git ~/cosmos
```

Now you can run the installer script:

```bash
$ cd ~/cosmos
$ ./cosmos-install.sh
```

## Switch to the Dev Branch

There are many changes present in the COSMOS Core dev branch that are not present in the master branch. To get the newest changes, switch to the dev branch:

```bin
$ cd ~/cosmos/source/core
$ git checkout dev
$ git fetch
```

## Compile COSMOS Core Locally

{% include important.html content="You can skip this step if you _only_ want to compile your programs to run on the BeagleBone." %}


In Qt Creator, click on _File_ > _Open File or Project..._, and open up the file `~/cosmos/source/core/CMakeLists.txt`.

**TODO:** a project configuration dialog might show up?

Once the project is finished loading, click the _Projects_ button on the left side of the window, and then click
on _Desktop_, and then click on _Build_ under it.

Make sure the build directory looks something like:

```
/home/YOUR_USERNAME/cosmos/source/core/build-core-Desktop-Debug
```

Now you can press <kbd>Control</kbd> + <kbd>B</kbd> (or the hammer icon at the bottom left) to build the project.
This can take a while.

All of the executables are now located in the build directory from above. They are nested in a bunch of different folders,
but we need to put them together all in the same folder. To do so, run the following command in a terminal (replacing `YOUR_USERNAME` with your username):

```bash
$ cd /home/YOUR_USERNAME/cosmos/source/core/build-core-Desktop-Debug
$ mkdir bin
$ find ./ -perm /a+x -exec cp {} bin \;
```

Now you can copy the contents of the `/home/YOUR_USERNAME/cosmos/source/core/build-core-Desktop-Debug/bin` folder to the `/home/YOUR_USERNAME/cosmos/bin` folder. There will be a bunch of files already in the destination folder, but you can remove the old ones (those are from the master branch).







## Compile COSMOS Core for the BeagleBone

{% include important.html content="You can skip this step if you _don't_ want to compile your programs to run on the BeagleBone." %}



### Install the ARM Toolchain

The ARM toolchain consists of cross-compilers for ARM-based processors, such as the ones used on the BeagleBone and Raspberry Pi.

First check if you already have the cross-compiler by running the following a terminal window:

```bash
$ /usr/bin/arm-linux-gnueabihf-gcc-4.9
```

If you get a message saying `No such file or directory`, then you'll need to install the cross-compiler. Otherwise, you can skip to [Clone COSMOS Core](#clone-cosmos-core)

Run the following command:

```bash
$ sudo gedit /etc/apt/sources.list
```

At the bottom of the file that opens, add the following two lines:

```
deb http://dk.archive.ubuntu.com/ubuntu/ xenial main 
deb http://dk.archive.ubuntu.com/ubuntu/ xenial universe
```

Save the file and close the window. Return the the terminal window and run:

```bash
$ sudo apt-get update
$ sudo apt-get install g++-4.9 gcc-4.9 gcc-4.9-arm-linux-gnueabihf g++-4.9-arm-linux-gnueabihf
```

Once this completes, open up the `sources.list` file again by running:

```bash
$ sudo gedit /etc/apt/sources.list
```

Remove the two lines you previously added at the bottom, and save the file.


### Set up the Cross Compiler in Qt Creator

Open up Qt Creator, and click on _Tools > Options_.


Click on the _Devices_ menu that appears near the bottom of the sidebar. Next, click the _Add_ button.

Select _Generic Linux Device_ and click _Start Wizard_. In the fields that appear, enter the following:

* **The name to identify this configuration:** BeagleBoneBlack
* **The device's hostname or IP address:** beaglebone.local
* **The username to log into the device:** debian

Click _Next_, then _Next_ again, and then _Finish_. Qt Creator will attempt to connect to the device, but you can cancel it for the time being.


Next, select _Kits_ at the top of the sidebar.


Click the _Add_ button on the right of the window. Enter the following text into the relevant fields:
* **Name:** ARM32
* **File system name:** arm32
* **Device type:** Generic Linux Device
* **Device:** BeagleBoneBlack
* Compiler
  * **C:** GCC 4.9 (C, arm 32bit ...)
  * **C++:** GCC 4.9 (C++, arm 32bit ...)

Next, click _OK_.


### Cross-Compile COSMOS Core

Now it's time to cross-compile for ARM.
<br>
In Qt Creator, click on _File_ > _Open File or Project..._, and open up the file `~/cosmos/source/core/CMakeLists.txt`.

**TODO:** a project configuration dialog might show up?

Once the project is finished loading, click the _Projects_ button on the left side of the window, and then click
on _ARM32_ (the kit we added in the previous step), and then click on _Build_ under it.

Make sure the build directory looks something like:

```
/home/YOUR_USERNAME/cosmos/source/core/build-core-arm32-Debug
```

Now you can press <kbd>Control</kbd> + <kbd>B</kbd> (or the hammer icon at the bottom left) to build the project.
This can take a while.


All of the executables are now located in the build directory from above. They are nested in a bunch of different folders,
but we need to put them together all in the same folder. To do so, run the following command in a terminal (replacing `YOUR_USERNAME` with your username):

```bash
$ cd /home/YOUR_USERNAME/cosmos/source/core/build-core-arm32-Debug
$ mkdir bin
$ find ./ -perm /a+x -exec cp {} bin \;
```

### Copy the Executables

Now you can copy the `/home/YOUR_USERNAME/cosmos/source/core/build-core-arm32-Debug/bin` folder to the `/home/debian/cosmos/bin` folder on the BeagleBone"

```bash
cd /home/YOUR_USERNAME/cosmos/source/core/build-core-arm32-Debug
rsync -auv ./bin debian@beaglebone.local:/cosmos/
```

{% include tip.html content="If you don't like using `rsync` to copy to the BeagleBone, you can use [FileZilla](https://filezilla-project.org/download.php) instead." %}

{% include note.html content="If you run into a warning saying `WARNING: POSSIBLE DNS SPOOFING DETECTED!`, then
you can try fixing this by running `rm ~/.ssh/known_hosts`" %}


### Add COSMOS to PATH

If running the command `agent` from Cloud9 doesn't work, then the BeagleBone doesn't have the COSMOS `bin`
folder added to the PATH variable. To add the folder, run the following in a Cloud9 terminal:

```bash
$ nano ~/.bashrc
```

This will open up the file containing the directories the shell looks for programs in.
Now, add the following line to the bottom of the file:

```
export PATH="$HOME/cosmos/bin:$PATH"
```

{% include tip.html content="Does the file look weird when scrolling? You can press <kbd>Control</kbd> + <kbd>L</kbd>
to manually refresh the view." %}

After you've added that line, press <kbd>Control</kbd> + <kbd>S</kbd> to save the file, and then
<kbd>Control</kbd> + <kbd>X</kbd> to exit.

Next, close the terminal window and open up a new one to reload the PATH. You should be able to run the following command
to see the usage of the program:

```bash
$ agent
```


## Grab the SimpleAgent Template (Optional)
If you want to use the SimpleAgent template project, you can clone it to your COSMOS project folder by
running the following in a terminal window:

```bash
$ cd ~/cosmos/source/projects
$ git clone https://github.com/mtmk-ee/simpleagent_template.git
```



## See Also
* [COSMOS Manual](https://docs.google.com/document/d/19rqvtZeEMJzkEcsTlC4ojYUkN-3OcYLc6IqRXgDIQlI)