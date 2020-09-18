---
title: Front Matter
layout: page
permalink: /pages/documentation/site/pages/contents.html

sidebar: dev_sidebar
search: exclude
---


## Front Matter

Front matter is a section at the top of every markdown page written in YAML. Its purpose is to instruct Jekyll
on how to generate the page, as well as to store page-specific settings. Below is a commented example of the front matter
from the Heater Agent page:


```yaml
---
# The title that shows up in the browser tab and as the main heading of the page
title: Heater Agent

# The permalink for this page. This overrides the actual location of the file
permalink: /pages/documentation/agents/heater-agent.html

# The type of page (e.g. agent, class, ...)
layout: agent

# Tags used by theme
tags: [software, heater]

# Keywords used to identify this page in the search bar
keywords: software

# A page-specific setting used by the agent layout
agent_name: agent_heater
---
```

The three dashes before and after the front matter section are required.

## Contents

Below the front matter is everything that will show up on the page. You can write whatever you wish in
Github-Flavored Markdown, HTML, and Liquid.

{% include important.html content="Be careful with indentation while working with HTML and Liquid, as using them
within a markdown file tends to cause issues. If you can't figure out why something isn't working, try removing all
indentation from the relevant section" %}