---
template: leetcode
title: Find the Difference
number: 1
link: https://leetcode.com/problems/find-the-difference/
---

## Using Hashmap

There are different ways to utilize hashmap in this problem.
Simple one is to create two hashmap and then check the item which has greater count.

```py
{{ include_file("solution.py")}}
```

## Using XOR property

XOR of two similar items have a cancellation effect.
$a \text{ XOR } b \text{ XOR } b = a$

```py
{{ include_file("solution2.py")}}
```
