---
title: Installing COSMOS From Scratch
permalink: /pages/tutorials/install/user-install.html
layout: page

tags: [software]
keywords: software

---

## Introduction

This is a quick install for general use of COSMOS. 

{% include warning.html content="It is still _highly_ recommended that you install COSMOS on Ubuntu 18.04 for compatibility." %}

If you do not have Ubuntu 18.04, it is recommended to install a virtual machine to emulate Ubuntu 18.04. If you are already using Ubuntu 18.04, please skip the installation of VirtualBox and start from [Dependencies](#dependencies).

### VirtualBox Installation
You can follow the instructions from [development environment]({{site.baseurl}}/pages/tutorials/setup/development-environment.html).

## Dependencies
Install dependencies by running the following in a terminal or command line:
```bash
$ sudo apt update && sudo apt upgrade -y
$ sudo apt-get install git cmake build-essential -y
  ```
{% include note.html content="In Ubuntu, highlight and press <kbd>ctrl</kbd>+<kbd>shift</kbd>+<kbd>c</kbd> to copy. To paste, press <kbd>ctrl</kbd>+<kbd>shift</kbd>+<kbd>v</kbd>"%}

## Clone COSMOS Core
Clone and run the installer script by executing the following:

```bash
$ git clone https://github.com/hsfl/cosmos-installer.git ~/cosmos
$ cd ~/cosmos
$ ./cosmos-install.sh
```

### Testing COSMOS
Let's test the installation of COSMOS.

Check that the ```bin``` folder was created under ```cosmos```:
```bash
$ cd ~/cosmos
$ ls
```

You should see ```bin``` as one of the outputs.

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

## (Optional) Install COSMOS Web
Here, we will install COSMOS Web, a website that helps visualize the telemetry data that comes in from the satellites. This allows you to host the website on your computer. 

### Install Docker
Docker helps create versions of code and sets up the environment to make it easier for it to be shared.

We will install the community edition of docker by following [this](https://docs.docker.com/engine/install/ubuntu/#install-using-the-repository) guide. The instructions are repeated below:

```bash
$ sudo apt-get update
$ sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    gnupg-agent \
    software-properties-common
$ curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
$ sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"
 $ sudo apt-get update
 $ sudo apt-get install docker-ce docker-ce-cli containerd.io
 ```

To test your docker installation, run:
```bash
$ sudo docker run hello-world
```

### Build Docker Image
Now that docker has been installed, we will build the COSMOS Web on our computers. To do so, run the following:

```bash
$ cd ~/cosmos
$ sudo docker build -t cosmos .
```

### Starting COSMOS Web
We can now run COSMOS Web on our computers with the command:
```bash
$ sudo docker run --network host --entrypoint "cosmos_web" cosmos
```

## See Also
* [COSMOS Manual](https://docs.google.com/document/d/19rqvtZeEMJzkEcsTlC4ojYUkN-3OcYLc6IqRXgDIQlI)
