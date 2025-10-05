package com.shivanshu;

/*
 * a subarray is special if OR
 * of all it's elements is >= k
 *
 * 1. sliding window can't be applied since there is no inverse of bitwise OR
 * 2. this may be related to dynamic programming but time complexity will be n^2, so not possible for 10^5
 * 3. we can use sliding window if we change the bitwise OR to normal addition, here we can represent the accumulation in a 32 bit array
 * */

public class Problem3097 {
    public void add_no(int no, int[] accumulation) {
        for (int i = 0; i < accumulation.length; i++) {
            accumulation[i] += ((no & 1 << i) != 0) ? 1 : 0;
        }
    }

    public void remove_no(int no, int[] accumulation) {
        for (int i = 0; i < accumulation.length; i++) {
            accumulation[i] -= ((no & 1 << i) != 0) ? 1 : 0;
        }
    }

    public int get_no(int[] accumulation) {
        int no = 0;
        for (int i = 0; i < accumulation.length; i++) {
            no += accumulation[i] != 0 ? (1 << i) : 0;
        }
        return no;
    }

    public int minimumSubarrayLength(int[] nums, int k) {
        int[] accumulation = new int[32];
        if (k == 0) return 1;
        int ans = Integer.MAX_VALUE;
        int left = -1, right = 0;

        while (left < right) {
            if (get_no(accumulation) < k) {
                if (right == nums.length) break;
                add_no(nums[right], accumulation);
                right++;
            } else {
                ans = Math.min(ans, right - left - 1);
                remove_no(nums[left + 1], accumulation);
                left++;
            }
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }

    public static void main(String[] args) {
        Problem3097 p = new Problem3097();
        {
            int[] a = {1, 2, 3};
            int k = 2;
            System.out.println(p.minimumSubarrayLength(a, k));
        }
        {
            int[] a = {2, 1, 8};
            int k = 10;
            System.out.println(p.minimumSubarrayLength(a, k));
        }
        {
            int[] a = {1, 2};
            int k = 0;
            System.out.println(p.minimumSubarrayLength(a, k));
        }
    }
}

