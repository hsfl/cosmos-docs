---
title: Agent Request Table
layout: page
permalink: /pages/documentation/site/includes/agents/request-table.html

sidebar: dev_sidebar
search: exclude
---

## Brief
The "Request Table" include generates a table of agent requests for a page using the `agent` layout.

This can be included in a page by using the following code:

{% raw %}
`{% include agents/request_table.html %}`
{% endraw %}


## The YAML File

This requires that a YAML file be placed in the `_data/agents` folder named according to the agent page's `agent_name` frontmatter field.

Here is an example taken from the `_data/agents/agent_heater.yml` YAML file:

```yaml
requests:
  - name: "Heater Control"
    usage: "state [on | off]"
    aliases: ["state", "set", "get"]
    brief: Enables, disables, or displays information for the heater device.
    note: |
      The argument is optional:
      * If `on` is given, the agent will turn on the heater
      * If `off` is given, the agent will turn off the heater.

      If this argument is not supplied, the status of the heater will be returned.
```
