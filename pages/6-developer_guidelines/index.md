---
title: Developer Guidelines
permalink: /pages/6-developer_guidelines/index.html
layout: page
index: 6

tags: [software]
keywords: software
---

## Main guidelines
- Don't make major changes to the existing structure without thorough testing
- Thorough testing involves:
  - Multiple use scenarios (core, projects, tools)
  - Clean tests (remove everything and build from scratch)

## Using branches
- `dev` should be used for development; it doesn’t have to compile successfully but should .
- `master` should always compile.
- Create new `dev-featurex` branches to develop new features.
