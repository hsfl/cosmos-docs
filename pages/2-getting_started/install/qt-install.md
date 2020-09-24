---
title: Install Qt
permalink: /pages/2-getting_started/install/qt-install.html
layout: page

tags: [software]
keywords: software

---


## Introduction

Qt is a cross-platform software development kit (SDK) that allows us to compile, build, and develop COSMOS.

## Installing
First check to see if you have Qt already installed. There are typically two places where it could be installed.
The first option is in the "user" folder:
```
$ cd ~/Qt
```
The second option is in the "opt" folder:
```
$ cd /opt/Qt
```
If Qt is not in either of these folders then you'll have to install it.
If you get an error message:
```
"bash: cd: /home/<user>/qt: No such file or directory"
```
Then you'll need to install Qt.

We recommend using the latest version of Qt because it is compatible with most of the COSMOS tools.
1. Go to this link: http://www.qt.io/download-open-source/ and download the open source (free) version of Qt to “Downloads” folder
2. Open the terminal in the “Downloads” folder
```
cd Downloads
```
3. Check the file name in the downloads folder and copy the file name
```
ls qt-unified-linux*
```
4. To start the installer you’ll have to make the installer script executable:
```
chmod +x qt-unified-linux*
sudo ./qt-unified-linux*
```
{% include note.html content="If you install with admin rights (sudo), you’ll install qt for everyone in the computer in /opt/Qt. Otherwise it will install in your home folder and only you can use it." %}


5. You’ll accept the default parameters on most of the dialogs. On the login dialog just hit the ‘skip’ button. Once you get to the “Select Components” menu make sure to select “desktop gcc 64-bit” version from the Qt menu as show in in the picture.

{% include image.html file="/resources/2-getting_started/install/qt/qt-install0.png" width="75%" %}

{% include image.html file="/resources/2-getting_started/install/qt/qt-install1.png" width="75%" %}
Select the latest version for Qt “Desktop gcc 64 bit”. The screenshot below is just for illustrative purposes.
{% include image.html file="/resources/2-getting_started/install/qt/qt-install2.png" width="75%" %}


## See Also
* [COSMOS Manual](https://docs.google.com/document/d/19rqvtZeEMJzkEcsTlC4ojYUkN-3OcYLc6IqRXgDIQlI)
* [Install Qt on Ubuntu](https://wiki.qt.io/Install_Qt_5_on_Ubuntu)
