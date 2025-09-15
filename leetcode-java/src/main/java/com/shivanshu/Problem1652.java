package com.shivanshu;

import java.util.Arrays;

public class Problem1652 {
    public int sum(int[] prefix_sum, int start, int end) {
        int n = prefix_sum.length - 1;
        if (start <= end) {
            return prefix_sum[end + 1] - prefix_sum[start];
        } else {
            return (prefix_sum[n] - prefix_sum[start]) + (prefix_sum[end + 1] - prefix_sum[0]);
        }
    }

    public int[] decrypt(int[] code, int k) {
        if (k == 0) {
            return new int[code.length];
        }
        int[] prefix_sum = new int[code.length + 1];
        for (int i = 0; i < code.length; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + code[i];
        }

        int[] ans = new int[code.length];
        int n = code.length;
        for (int i = 0; i < n; i++) {
            int start = (k > 0) ? (i + 1) % n : (i + k + n) % n;
            int end = (k > 0) ? (i + k) % n : (i - 1 + n) % n;
            ans[i] = sum(prefix_sum, start, end);
        }
        return ans;
    }

    public static void main(String[] args) {
        Problem1652 p = new Problem1652();
        /*{
            int[] code = {5, 7, 1, 4};
            int k = 3;
            System.out.println(Arrays.toString(p.decrypt(code, k)));
        }
        {
            int[] code = {1, 2, 3, 4};
            int k = 0;
            System.out.println(Arrays.toString(p.decrypt(code, k)));
        }
        {
            int[] code = {2, 4, 9, 3};
            int k = -2;
            System.out.println(Arrays.toString(p.decrypt(code, k)));
        }
        {
            int[] code = {2, 4, 2, 4, 10, 3, 10, 7, 10, 5};
            int k = 1;
            System.out.println(Arrays.toString(p.decrypt(code, k)));
        }*/
        {
            int[] code = {10, 5, 7, 7, 3, 2, 10, 3, 6, 9, 1, 6};
            int k = -4;
            System.out.println(Arrays.toString(p.decrypt(code, k)));
        }
    }
}
