package com.shivanshu;

import java.util.Arrays;

public class Problem862 {

    public int shortestSubarray(int[] nums, int k) {
        int min_no = Arrays.stream(nums).min().getAsInt();
        if (min_no < 0) {
            for (int i = 0; i < nums.length; i++) {
                nums[i] += -min_no;
            }
            k += -min_no;
        }

        int currSum = 0;
        int ans = Integer.MAX_VALUE;
        int left = -1;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] + currSum >= k) {
                ans = Math.min(ans, i - left);
                currSum += nums[i];

                // reducing windows size
                while (left <= i && currSum >= k) {
                    currSum -= nums[left + 1];
                    left++;
                    ans = Math.min(ans, i - left);
                }
            } else {
                currSum += nums[i];
            }
        }
        while (left <= nums.length - 1 && currSum >= k) {
            currSum -= nums[left + 1];
            left++;
            ans = Math.min(ans, nums.length - 1 - left);
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}
