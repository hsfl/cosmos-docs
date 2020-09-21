---
title: Doxygen
permalink: /pages/documentation/other/doxygen.html
layout: page

keywords: software
---

## What is this for?

Doxygen can generate detailed documentation for the COSMOS software, far beyond the documentation
included on this website.


## Generating the Docs

Enter the following a terminal window:

```bash
$ cd ~/cosmos/source/core/docs/doxygen
$ doxygen
```

You can then view the generated site by running:

```bash
$ xdg-open 1.0.2/index.html
```

Optionally, you can navigate in the file explorer to the `~/cosmos/source/core/docs/doxygen/1.0.2`
folder and open up the `index.html` file.

{% include tip.html content="If you visit the Doxygen docs frequently, you should bookmark the `index.html` file.
Otherwise you would need to dig through all the files every time!" %}
