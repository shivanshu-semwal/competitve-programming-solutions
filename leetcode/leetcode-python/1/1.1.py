""" 
link: https://leetcode.com/problems/two-sum
tags:
- array
- hash-table
"""

import array, bisect, collections, functools, heapq, itertools, math, operator, random, re, string, sys, time
from typing import List, Optional, Any


""" 
Using Hashmap
- $n$ - length of list
- Time Complexity - $O(n)$
- Space Complexity - $O(n)$
"""


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        items = [[nums[i], i] for i in range(0, len(nums))]
        items.sort(key=lambda x: x[0])

        left, right = 0, len(items) - 1
        while left < right:
            sum = items[left][0] + items[right][0]
            if sum == target:
                return [items[left][1], items[right][1]]

            if sum < target:
                left += 1
            else:
                right -= 1

        return None
