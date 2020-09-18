---
title: Quick Details Table
layout: page
permalink: /pages/documentation/site/includes/agents/quick-details.html

sidebar: dev_sidebar
search: exclude
---

## Brief
The "Quick Details" include generates a quick details table for a page using the `agent` layout.

This can be included in a page by using the following code:

{% raw %}
`{% include agents/detail_table.html %}`
{% endraw %}


## The YAML File

This requires that a YAML file be placed in the `_data/agents` folder named according to the agent page's `agent_name` frontmatter field.

Here is an example taken from the `_data/agents/agent_heater.yml` YAML file:

```yaml
description:
  program_name: agent_heater
  agent_name: heater
  files:
    - name: "agent_heater.cpp"
  hardware:
    - name: "Heater"
    - name: "Power Distribution Unit (PDU)"
```
