---
title: Includes
layout: page
permalink: /pages/documentation/site/includes/index.html

sidebar: dev_sidebar
search: exclude
---

## Brief

Includes are HTML files that can be pasted ("included") into a page using Liquid code.

For example, to include the `head.html` file from the `_includes` folder, you could write:

{% raw %}
`{% include head.html %}`
{% endraw %}

You can also pass parameters like so (this is only for demonstration):

{% raw %}
`{% include head.html param_one="my value" param_two=20 %}`
{% endraw %}

## See Also
* [Jekyll Documentation - Includes](https://jekyllrb.com/docs/includes/)