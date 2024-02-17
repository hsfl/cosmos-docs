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

## Developer Code Contributions

We encourage any developer to contribute to the COSMOS repositories. The following steps show how anyone can successfully push their code to the main COSMOS repositories

configure
git config --global pull.ff only (to set fast forward merges globally) 

1. git fork the code repository you are interested in
3. git clone (you now have permissions to edit your fork)
4. create a new feature branch 'ex: feature-save-agent007'
5. build your amazing feature code and make sure it compiles successfully 
6. git add
8. git commit
9. git pull --rebase
10. resolve any conflicts if they exist
11. git push to your fork
12. git pull request to the main repo
