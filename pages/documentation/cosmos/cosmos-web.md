---
title: COSMOS Web
permalink: /pages/documentation/cosmos/cosmos-web.html
layout: page

tags: [software]
keywords: software

---


## What is COSMOS Web?

COSMOS Web is a web-based GUI for COSMOS missions. It provides a far more convenient way of gathering information
from COSMOS agents than the traditional command line method.

## Starting COSMOS Web

### With the Development Environment

If you are using the development environment, you can simply run the following command in a terminal:

```bash
$ ~/cosmos-web.sh
```

A browser window should open up and display the COSMOS Web homepage. If not, you can go to
[http://0.0.0.0:5000/](http://0.0.0.0:5000/) in your browser.

### Without the Development Environment

For convenience you should make a shell script. Create a file called `cosmos-web.sh` in the home directory in Ubuntu,
and paste the following contents:

```bash
#!/bin/bash

sudo systemctl start mongod

~/cosmos/tools/agent_mongo --realm artemis &
cd ~/cosmos/source/tools/cosmos-web
npm start && fg
```

Save the file, and run the following command in a local terminal:

```bash
$ sudo chmod +x ~/cosmos-web.sh
```

Now you can start COSMOS Web by running this script:

```bash
$ ~/cosmos-web.sh
```

A browser window should open up and display the COSMOS Web homepage. If not, you can go to
[http://0.0.0.0:5000/](http://0.0.0.0:5000/) in your browser.
