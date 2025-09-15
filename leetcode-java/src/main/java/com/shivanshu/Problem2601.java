package com.shivanshu;

/*
 * 1. guess -> is this related to simulation? pick a prime and try to find a solution, no
 * 2. guess, since n < 1000 this means that n^2 and n^3 may work out
 * 3. guess, i think simulations may be the answer, we reduce each number to the minimum we can and then go the next element and try to reduce it so that it is greater than current element, if that is not possible than return false. now how do find the nearest prime number near it, i can create a array and than use it*/

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Problem2601 {

    public List<Integer> primes;

    public void preprocess_primes() {
        int NO_PRIMES = 1002;
        boolean[] a = new boolean[NO_PRIMES];
        // a[i] = true means has a divisor
        a[1] = true; // 1 is not prime
        for (int i = 2; i * i <= NO_PRIMES; i++) {
            if (a[i]) continue;
            for (int j = i + i; j < NO_PRIMES; j += i) a[j] = true;
        }

        primes = new ArrayList<Integer>();
        for (int i = 0; i < a.length; i++) if (!a[i]) primes.add(i);
    }

    public int findNearestSmallerPrime(int target) {
        int left = 0, right = primes.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (primes.get(mid) <= target) {
                result = primes.get(mid);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }

    public boolean primeSubOperation(int[] nums) {
        int prev = 0;
        preprocess_primes();
        for (int i = 0; i < nums.length; i++) {
            System.out.println(nums[i] + ":" + prev);
            int curr = nums[i];
            if (curr <= prev) {
                return false;
            } else {
                int diff = Math.min(curr - prev - 1, curr - 1); // fit the largest prime you can find here
                int lower_bound = findNearestSmallerPrime(diff);
                if (lower_bound == -1) return false;
                nums[i] = curr - lower_bound;
                prev = nums[i];
            }
        }
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
        return true;
    }

    public static void main(String[] args) {
        Problem2601 p = new Problem2601();
        {
            int[] nums = {18,12,14,6};
            System.out.println(p.primeSubOperation(nums));
        }

        {
            int[] nums = {998, 2};
            System.out.println(p.primeSubOperation(nums));
        }

//        {
//            p.preprocess_primes();
//            System.out.println(p.findNearestSmallerPrime(10));
//        }
    }
}


