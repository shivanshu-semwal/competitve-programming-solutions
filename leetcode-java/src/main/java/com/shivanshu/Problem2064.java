package com.shivanshu;

import java.util.Arrays;
import java.util.stream.IntStream;

/*
* suppose answer is x, then sum(quantities) <= x * n
* so we have to find the minimum x for which this inequality satisifies
* */
public class Problem2064 {

    public boolean canBeDone(int[] quantities, int n, int k){
        int containers = 0;
        for(int i=0;i<quantities.length;i++){
            int quantity_to_give = Math.min(quantities[i], k);
            containers += (int) Math.ceil(quantities[i] / (double) quantity_to_give);
        }
        return containers <= n;
    }

    public int minimizedMaximum(int n, int[] quantities) {
        long sum = IntStream.of(quantities).sum();

        int lower_bound = (int) Math.ceil(sum / (double) n);
        int upper_bound = Arrays.stream(quantities).max().getAsInt();

        int ans = upper_bound;
        while (lower_bound <= upper_bound) {
            int mid = lower_bound + (upper_bound - lower_bound) / 2;
            if (canBeDone(quantities, n, mid)) {
                ans = mid;
                upper_bound = mid - 1;
            } else {
                lower_bound = mid + 1;
            }
        }
        return ans;
    }
}
