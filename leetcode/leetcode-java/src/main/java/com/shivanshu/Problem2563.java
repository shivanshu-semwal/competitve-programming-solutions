package com.shivanshu;

import java.util.Arrays;

public class Problem2563 {

    public int count(int[] nums, int lower, int upper, int start_idx) {
//        System.out.printf("%s: %d %d %d\n", Arrays.toString(nums), lower, upper, start_idx);
        int left = start_idx + 1, right = nums.length - 1;
        int top = start_idx;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= upper) {
                top = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        int bottom = nums.length;
        left = start_idx + 1;
        right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= lower) {
                bottom = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
//        System.out.printf("top: %d bottom: %d\n", top, bottom);
        return top >= bottom ? top - bottom + 1 : 0;
    }

    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        long ans = 0;

        for (int i = 0; i < nums.length - 1; i++) {
            // find all numbers in the range lower <= num + y <= upper
            // lower - num <= y <= upper - num, find all y that satisfy this
            int curr_ans = count(nums, lower - nums[i], upper - nums[i], i);
            ans += curr_ans;
//            System.out.println(curr_ans);
        }

        return ans;
    }

    public static void main(String[] args) {
        Problem2563 p = new Problem2563();
        {
            int[] nums = {0, 1, 7, 4, 4, 5};
            int lower = 3, upper = 6;
            System.out.println(p.countFairPairs(nums, lower, upper));
        }
        {
            int[] nums = {1, 7, 9, 2, 5};
            int lower = 11;
            int upper = 11;
            System.out.println(p.countFairPairs(nums, lower, upper));
        }
    }
}
