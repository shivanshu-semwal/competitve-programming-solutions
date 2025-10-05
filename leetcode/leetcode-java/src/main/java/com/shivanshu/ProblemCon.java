package com.shivanshu;

class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int size = colors.length;

        int ans = 0;
        boolean prev = false;

        for (int i = 0; i < size; ) {
            boolean flag = true;

            int start = (prev ? (i + k - 2) : (i + 1)) % size;
            int end = (i + k - 1) % size;
            for (int j = start; j != end; j = (j + 1) % size) {
                int back = ((j - 1) >= 0) ? (j - 1) : (j - 1 + size);
                int next = (j + 1) % size;
                if (colors[back] != colors[j] && colors[next] != colors[j]) {
                    continue;
                } else {
                    flag = false;
                    i = (j > i) ? j : i + 1;
                    break;
                }
            }
            if (flag) {
                i++;
                ans++;
                prev = true;
            }
        }
        return ans;
    }
}

public class ProblemCon {

    public static void main(String[] args) {
        {
            Solution p = new Solution();
            int[] colors = {0,0,1,0,1};
            int k = 5;
            System.out.println(p.numberOfAlternatingGroups(colors, k));
        }
    }
}
