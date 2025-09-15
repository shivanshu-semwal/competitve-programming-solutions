package com.shivanshu;

import java.util.Arrays;
import java.util.Comparator;

public class Problem2070 {
    public int solve(int[][] items, int query) {
        // find the smallest item with price query and return the item less than it
        int left = 0, right = items.length - 1;
        int idx = items.length;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (items[mid][0] > query) {
                idx = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        int ans_idx = idx - 1;
        if (ans_idx == -1) return 0;
        else return items[ans_idx][1];
    }

    public int[] maximumBeauty(int[][] items, int[] queries) {
        Arrays.sort(
                items,
                (item1, item2) -> item1[0] == item2[0]
                        ? Integer.compare(item1[1], item2[1])
                        : Integer.compare(item1[0], item2[0])
        );

        // propagate the beauty
        for (int i = 0; i < items.length; i++) {
            items[i][1] = Integer.max(items[i][1], i == 0 ? 0 : items[i - 1][1]);
        }

        // perform binary search
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            ans[i] = solve(items, queries[i]);
        }
        return ans;
    }

    public static void main(String[] args) {
        Problem2070 p = new Problem2070();
        {
            int[][] items = {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}};
            int[] queries = {1, 2, 3, 4, 5, 6};
            int[] result = p.maximumBeauty(items, queries);
            System.out.println(Arrays.toString(result));
        }
    }
}
