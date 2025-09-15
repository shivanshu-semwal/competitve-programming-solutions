""" 
link: https://leetcode.com/problems/two-sum
tags:
- array
- hash-table
"""
import array, bisect, collections, functools, heapq, itertools, math, operator, random, re, string, sys, time
from typing import List, Optional, Any


"""
Brute force appoach

- $n$ - length of list
- Time Complexity - $O(n^2)$
- Space Complexity - $O(1)$
"""

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        items = {}
        for i in range(0, len(nums)):
            no0 = nums[i]
            no1 = target - no0
            if no1 in items:
                return [i, items[no1]]

            items[no0] = i

        return None
