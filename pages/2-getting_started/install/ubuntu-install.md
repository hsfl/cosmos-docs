---
title: Installing COSMOS
layout: series
permalink: /pages/2-getting_started/install/ubuntu-install.html
index: 2.2
tags: [software]
keywords: software
sidebar: home_sidebar
toc: false


series:
  prev: /pages/2-getting_started/development-environment.html
  next: /pages/2-getting_started/install/cosmos-web.html
---


## Introduction

If you want to install COSMOS without using the development environment, you can always install COSMOS from scratch.

{% include warning.html content="It is still _highly_ recommended that you install COSMOS on Ubuntu 18.04.3 for compatibility." %}

## Dependencies
COSMOS depends on Git, CMake 2.8.12+ and Build Essential to function.
- Git
  - A version control manager that COSMOS depends on.
- CMake  2.8.12+
  - A cross-platform set of tools that packages COSMOS code and compiles it.
- Build essential
  - Compilers (gcc, g++ and their dependencies) that builds COSMOS code.

First you should make sure that you have all the dependencies you need by running the following in a terminal window:

```bash
$ sudo apt update && sudo apt upgrade -y
$ sudo apt-get install git cmake build-essential -y
  ```
## Clone COSMOS Core
Clone the installer script:

```bash
$ git clone https://github.com/hsfl/cosmos-installer.git ~/cosmos
```

Run the installer script:

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

## Build COSMOS Core with Qt Creator

{% include important.html content="You can skip this step if you _only_ want to compile your programs on the command line." %}

### Install Qt
For Qt Installation process, follow [these instructions]({{site.baseurl}}/pages/2-getting_started/install/qt-install.html).

In Qt Creator, click on _File_ > _Open File or Project..._, and open up the file `~/cosmos/source/CMakeLists.txt`.

**TODO:** a project configuration dialog might show up?

Once the project is finished loading, click the _Projects_ button on the left side of the window, and then click
on _Desktop_, and then click on _Build_ under it.

Make sure the build directory looks something like:

```
/home/YOUR_USERNAME/cosmos/source/build-core-Desktop-Debug
```

Now you can press <kbd>CTRL</kbd> + <kbd>B</kbd> (or the hammer icon at the bottom left) to build the project.
This can take a while.

All of the executables are now located in the build directory from above. They are nested in a bunch of different folders,
but we need to put them together all in the same folder. To do so, run the following command in a terminal (replacing `YOUR_USERNAME` with your username):

```bash
$ cd /home/YOUR_USERNAME/cosmos/source/build-core-Desktop-Debug
$ mkdir bin
$ find ./ -perm /a+x -exec cp {} bin \;
```

Now you can copy the contents of the `/home/YOUR_USERNAME/cosmos/source/core/build-core-Desktop-Debug/bin` folder to the `/home/YOUR_USERNAME/cosmos/bin` folder. There will be a bunch of files already in the destination folder, but you can remove the old ones (those are from the master branch).

### Testing COSMOS
1. Navigate to the “Projects” tab on the left menu.
2. Under “Build & Run” on the left menu, click the “Run” under the same kit you built with.
3. Under the Run category, select agent_001 under the run configuration. To run it, press Ctrl + R.
4. Now select agent_002 under the run configuration. Again, press Ctrl + R to run it.

The agents should now be talking to each other.
This illustrates the interconnectivity aspect of COSMOS and its ability to piece together heterogeneous systems.

## Build COSMOS Core on the Command Line
### Build COSMOS Core
To build COSMOS, open a terminal and type:
```bash
$ cd ~/cosmos/source/core/build
$ mkdir linux
$ ./do_cmake linux
$ cd linux
$ make -j
$ make -j install
```
### Testing COSMOS
Let's test the installation of COSMOS
Run the following commands in a terminal:
```bash
$ cd ~/cosmos/bin
$ ./agent_002
```

In another terminal, run:
```bash
$ cd ~/cosmos/bin
$ ./agent_001
```

The agents should now be talking to each other.
This illustrates the interconnectivity aspect of COSMOS and its ability to piece together heterogeneous systems.




## Add COSMOS to PATH

A path allows easy access to executable programs. Through this method, you will be able to run agents globally; simply add the `cosmos/bin` folder to the path.
Enter into the terminal:


```bash
$ nano ~/.bashrc
```

This will open up the file containing the directories the shell looks for programs in.
Now, add the following line to the bottom of the file:

```
export PATH="$HOME/cosmos/bin:$PATH"
```

{% include tip.html content="Does the file look weird when scrolling? You can press <kbd>CTRL</kbd> + <kbd>L</kbd>
to manually refresh the view." %}

After you've added that line, press <kbd>CTRL</kbd> + <kbd>S</kbd> to save the file, and then
<kbd>CTRL</kbd> + <kbd>X</kbd> to exit.

Next, close the terminal window and open up a new one to reload the PATH. You should be able to run the following command
to see the usage of the program:

```bash
$ agent
```




## See Also
* [COSMOS Manual](https://docs.google.com/document/d/19rqvtZeEMJzkEcsTlC4ojYUkN-3OcYLc6IqRXgDIQlI)
