---
title: Site Structure
layout: page
permalink: /pages/documentation/site/structure.html

search: exclude
---


## Brief

Below is an overview of the important components to the site structure. Folders beginning with
`_` are not copied to the folder containing the generated site.

```
├── _data                # Contains YAML data files which can be used as Liquid site variables
├── _includes            # Contains HTML/Liquid template files to be used in pages
├── _layouts             # Contains the HTML base files for Jekyll layouts.
├── _site                # Contains the generated site. Don't put your files in here!
├── css                  # Contains CSS files
├── js                   # Contains script files
| 
├── pages                # Contains markdown (.md) files corresponding to the actual pages
│   ├── documentation    # Documentation pages
│   ├── tutorials        # Tutorial pages
│   └── other            # Other pages
├── resources            # Resources (e.g. images)
```


