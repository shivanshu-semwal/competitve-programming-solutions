""" 
link: https://leetcode.com/problems/two-sum
tags:
- array
- hash-table
"""

import array, bisect, collections, functools, heapq, itertools, math, operator, random, re, string, sys, time
from typing import List, Optional, Any

""" 
Sorting and then two pointer

If we are given sorted array we can solve this using two pointer approach.
Since we have to return index and not the number, we have to create another list with no. and it's index.

- $n$ - length of list
- Time Complexity - $O(n \log(n))$
- Space Complexity - $O(n)$
"""


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(0, len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]

        return None
