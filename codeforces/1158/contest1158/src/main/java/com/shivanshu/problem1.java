package com.shivanshu;

import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class problem1 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n, m;
        n = sc.nextInt();
        m = sc.nextInt();

        ArrayList<Integer> b = new ArrayList<>(n);
        for (int i = 0; i < n; i++)
            b.add(sc.nextInt());

        ArrayList<Integer> g = new ArrayList<>(m);
        for (int i = 0; i < m; i++)
            g.add(sc.nextInt());

        sc.close();

        // System.out.println(b);
        // System.out.println(g);

        System.out.println(solve(n, m, b, g));
    }

    public static Integer findMaxSmallerElement(ArrayList<Integer> list, int start, int end, int number) {
        int left = start;
        int right = end;
        Integer result = null;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (list.get(mid) >= number) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;// min of what all boy give
            }
        }

        return result;
    }

    public static long solve(int n, int m, ArrayList<Integer> b, ArrayList<Integer> g) {
        long ans = 0;

        for (int i = 0; i < b.size(); i++)
            ans += b.get(i);
        ans *= m;

        b.sort((x, y) -> x > y ? -1 : 1);
        g.sort((x, y) -> x > y ? -1 : 1);

        // System.out.println(b);
        // System.out.println(g);

        int min_g = Collections.min(g);
        int max_b = Collections.max(b);

        if (min_g < max_b)
            return -1;

        int counter = 0;
        boolean flag = false;
        for (int i = 0, j = 0; i < g.size(); i++) {
            ans = ans + g.get(i) - b.get(j);
        }

        return ans;
    }
}