---
template: leetcode
title: Longest String Chain
number: 1048
link: https://leetcode.com/problems/longest-string-chain/
tags:
- Array
- Hash Table
- Two Pointers
- String
- Dynamic Programming
---

## Dynamic Programming

This problem is like this:

Given a list of *items* $L$, and a relation $R$ on items.

You have to find the length of longest list $l$ which is composed of elements of $L$,
such that, $(l_0, l_1) \in R, (l_1, l_2) \in R, \cdots, (l_{n-1}, l_n) \in R$

Here the relation $R$ is *predecessor*, which is defined as, $(x, y) \in R$, iff remove a character from $y$ and it becomes equivalent to $x$.

Relation $R$ has following properties:

- if $(x, y) \in R$, then $\operatorname{len}(x) + 1 = \operatorname{len}(y)$
    - so, if we have $x$ we only have to check for $y$ with this property
    - for this we can do sort the list based on words length
    - or we can create a dictionary based on length of words

### Using sorting

- Each subproblem in this problem uniquely identified by the index of word, so we only need a single dimensional table to sore result of a state.

```py
{{ include_file("solution.py") }}
```

### Using a dictionary

- Here a subproblem state is defined by, the length of word and it's index in the list of length of that words. So we need a 2d table.

```py
{{ include_file("solution2.py") }}
```
