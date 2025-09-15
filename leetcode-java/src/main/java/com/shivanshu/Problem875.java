package com.shivanshu;

import java.util.Arrays;

public class Problem875 {

    public int timeToEat(int[] piles, double k) {
        int time = 0;
        for (int i = 0; i < piles.length; i++) {
            time = time + (int) Math.ceil(piles[i] / k);
        }
        return time;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int lower_limit = Arrays.stream(piles).min().orElse(0);
        int upper_limit = Arrays.stream(piles).max().orElse(Integer.MAX_VALUE);
        int ans = Integer.MAX_VALUE;
        while (lower_limit < upper_limit) {
            int mid = lower_limit + (upper_limit - lower_limit) / 2;
            System.out.println(mid + " " + timeToEat(piles, mid));
            if (timeToEat(piles, mid) <= h) {
                ans = Math.min(ans, mid);
                upper_limit = mid - 1;
            } else {
                lower_limit = mid + 1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        {
            Problem875 s = new Problem875();
            int[] piles = {3, 6, 7, 11};
            int h = 8;
            System.out.println(s.minEatingSpeed(piles, h));
        }
    }
}
