package com.shivanshu;

public class Problem1574 {
    public int getUpperBound(int[] arr, int start, int end, int target) {
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] >= target) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }

    public int findLengthOfShortestSubarray(int[] arr) {
        int begin_idx = 0;
        int end_idx = arr.length - 1;

        for (int i = 0; i < arr.length && (i == 0 || arr[i] >= arr[i - 1]); i++) begin_idx = i;
        if(begin_idx == arr.length - 1) return 0; // no need to remove

        for (int i = arr.length - 1; i >= 0 && (i == arr.length - 1 || arr[i] <= arr[i + 1]); i--) end_idx = i;
        if(end_idx == 0) return arr.length - 1; // keep one element

        int ans = Math.min(end_idx, arr.length - begin_idx - 1);

        for (int i = 0; i <= begin_idx; i++) {
            int right_part = getUpperBound(arr, end_idx, arr.length - 1, arr[i]);
            if (right_part == -1) break;
            int subarray_len = arr.length - (i + 1 + arr.length - right_part);
            ans = Math.min(ans, subarray_len);
        }
        return ans;
    }

    public static void main(String[] args) {
        Problem1574 p = new Problem1574();
        {
            int[] arr = {10,13,17,21,15,15,9,17,22,22,13};
            p.findLengthOfShortestSubarray(arr);
        }
    }
}
