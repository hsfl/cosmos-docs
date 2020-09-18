---
title: FAQ Layout
layout: page
permalink: /pages/documentation/site/layouts/faq.html

sidebar: dev_sidebar
search: exclude
---

## Brief

FAQ pages should use the `faq` layout. To do so, include the following in the page's frontmatter:

```yaml
layout: faq
```

The layout file is located under `_layouts/faq.html`.

## Page Format
The agent layout is structured as follows:

1. (page contents)
2. FAQ List

## FAQ Configuration
Every page using the `faq` layout should declare which FAQ configuration they are using:

```yaml
faq: my_faq
```

This will direct the include to the `_data/faq/my_faq.yml` file in the example above.

An example of the YAML file:

```yaml
sections:

  - name: "Section Name"
    content:

      - question: "Question 1"
        answer: "Answer 1"

      - question: "Question 2"
        answer: "Answer 2"
```
