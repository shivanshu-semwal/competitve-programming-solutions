package com.shivanshu;

import java.util.Arrays;

/*
 * sliding window technique
 * */

public class Problem3254 {
    public int[] resultsArray(int[] nums, int k) {
        int[] ans = new int[nums.length - k + 1];

        boolean calculate = true;

        int i = 0;
        while (i < nums.length - k + 1) {
            if (calculate) {
                int j = i;
                while (j < i + k - 1) {
                    if (j == nums.length - 1 || nums[j] + 1 == nums[j + 1]) j++;
                    else break;
                }
                if (j == i + k - 1) {
                    ans[i] = nums[i + k - 1];
                    calculate = false;
                    i++;
                } else {
                    for (int c = i; c <= j; c++) ans[c] = -1;
                    i = j + 1;
                    calculate = true;
                }
            } else {
                if(k == 1 || nums[i + k - 2] + 1 == nums[i + k - 1]){
                    ans[i] = nums[i + k - 1];
                    i++;
                    calculate = false;
                } else {
                    ans[i] = -1;
                    i++;
                    calculate = true;
                }
            }
        }


        return ans;
    }

    public static void main(String[] args) {
        Problem3254 p = new Problem3254();
        {
            int[] arr = {4,30,31,32,33,34,5,6,4,4};
            int k = 5;
            System.out.println(Arrays.toString(p.resultsArray(arr, k)));
        }
    }
}
