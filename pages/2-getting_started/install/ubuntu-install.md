---
title: "Install COSMOS Core on Ubuntu"
layout: series
index: 2.2.3
permalink: /pages/2-getting_started/install/ubuntu-install.html
toc: false

tags: [software]
keywords: software
sidebar: home_sidebar

series:
  prev: /pages/2-getting_started/install/docker-install.html
  next: /pages/2-getting_started/install/cosmos-web.html
---


## Introduction

This tutorial will help you install the COSMOS core programs and libraries on a Linux Ubuntu environment. This assumes you already have Ubuntu installed (natively, via Virtual Box or WSL). If you're on the macOS you can also follow these instructions.

{% include warning.html content="It is still _highly_ recommended that you install COSMOS on Ubuntu 18.04.3 for compatibility." %}

## Dependencies
COSMOS depends on Git, CMake 2.8.12+ and Build Essential to function.
- Git
  - A version control manager used for most modern software development 
  - To learn more about Git see the [HSFL guide on getting started with Git](https://docs.google.com/document/d/1wMfGmQrrwGb9nrq0Mgbzm1sq9-XTwk3qJ2S1dyUw480/edit?usp=sharing) and the [Git Handbook](https://guides.github.com/introduction/git-handbook/) 
- CMake  2.8.12+
  - A cross-platform tool to manage building source code.
  - To learn more about Cmake follow the documentation links on the [official Cmake page](https://cmake.org/)
- Build essential packages
  - Compilers (gcc, g++ and their dependencies) that builds COSMOS code.

Before anything else make sure that you have all the dependencies you need by running the following commands in a terminal window:

```bash
sudo apt update && sudo apt upgrade -y
sudo apt-get install git cmake build-essential -y
  ```
## Build COSMOS Core

### Add your ssh key to github.com

```bash
ssh-keygen 
cat ~/.ssh/id_rsa.pub
```
Accept all questions with return. Only perform this step if you have not already created a key.
Copy this text and add it as a ssh key in your github account settings.

### Clone the COSMOS installer script:

```bash
git clone git@github.com:hsfl/cosmos-installer.git ~/cosmos
```

### Run the installer script:

```bash
cd ~/cosmos
./cosmos-install.sh developer
```

### Testing COSMOS Core
Let's test the installation of COSMOS by running two software agents (agent_001, agent_002) 
Run the following commands in a terminal:
```bash
agent_002
```

Open another terminal, run:
```bash
agent_001
```

The agents should now be talking to each other. This illustrates the interconnectivity aspect of COSMOS and its ability to piece together heterogeneous systems.
If the terminal reported an error while starting the agent command please [check if the PATH env variable was set correctly during the installation process](https://hsfl.github.io/cosmos-docs/pages/2-getting_started/install/ubuntu-install.html#add-cosmos-to-path).

Alternatively you can start the programs by changing to the cosmos/bin directory and running
```bash
cd ~/cosmos/bin
./agent_001
```



## Build COSMOS Core with Qt Creator (Optional)

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
cd /home/YOUR_USERNAME/cosmos/source/build-core-Desktop-Debug
mkdir bin
find ./ -perm /a+x -exec cp {} bin \;
```

Now you can copy the contents of the `/home/YOUR_USERNAME/cosmos/source/core/build-core-Desktop-Debug/bin` folder to the `/home/YOUR_USERNAME/cosmos/bin` folder. There will be a bunch of files already in the destination folder, but you can remove the old ones (those are from the master branch).

### Testing COSMOS on Qt Creator
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
cd ~/cosmos/source/core/build
mkdir linux
./do_cmake linux
cd linux
make -j8
make -j8 install
```

## Switch to the Dev Branch (Optional)

There are many changes present in the COSMOS Core dev branch that are not present in the master branch. To get the newest changes, switch to the dev branch:

```bash
cd ~/cosmos/source/core
git checkout dev
git fetch
```


## Add COSMOS to PATH

A path allows easy access to executable programs. Through this method, you will be able to run agents globally; simply add the `cosmos/bin` folder to the path.
Enter into the terminal:


```bash
nano ~/.bashrc
```

This will open up the file containing the directories the shell looks for programs in.
Now, add the following line to the bottom of the file:

```
export PATH="$HOME/cosmos/bin:$PATH"
```

{% include tip.html content="You need to edit the file without getting into nano-specific <kbd>CTRL</kbd> + <kbd>L</kbd> commands." %}

<!--{% include tip.html content="Does the file look weird when scrolling? You can press <kbd>CTRL</kbd> + <kbd>L</kbd>
to manually refresh the view." %}-->

After you've added that line, press <kbd>CTRL</kbd> + <kbd>S</kbd> to save the file, and then
<kbd>CTRL</kbd> + <kbd>X</kbd> to exit.

Next, close the terminal window and open up a new one to reload the PATH. You should be able to run the following command
to see the usage of the program:

```bash
agent
```

## See Also
* [COSMOS Manual](https://docs.google.com/document/d/19rqvtZeEMJzkEcsTlC4ojYUkN-3OcYLc6IqRXgDIQlI)
* [Original "Install COSMOS on Linux Ubuntu" doc](https://docs.google.com/document/d/1jCWwJyiwQVfwtHrvJwAQ4vTe55TE-UGZzd0wIU9yiig/edit#heading=h.uydetxsepgs0)
