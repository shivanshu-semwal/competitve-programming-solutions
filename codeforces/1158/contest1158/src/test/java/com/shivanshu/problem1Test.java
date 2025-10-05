package com.shivanshu;

import org.junit.Test;
import static org.junit.Assert.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

import com.shivanshu.problem1;

public class problem1Test {
    @Test
    public void testFindMaxSmallerElement() {
        ArrayList<Integer> list = new ArrayList<>(Arrays.asList(1, 3, 5, 7, 9, 11));

        assertEquals(Integer.valueOf(3), problem1.findMaxSmallerElement(list, 0, list.size() - 1, 6));
        assertEquals(null, problem1.findMaxSmallerElement(list, 0, list.size() - 1, 12));
        assertEquals(Integer.valueOf(0), problem1.findMaxSmallerElement(list, 0, list.size() - 1, 1));
        assertEquals(Integer.valueOf(5), problem1.findMaxSmallerElement(list, 0, list.size() - 1, 11));
        assertEquals(Integer.valueOf(5), problem1.findMaxSmallerElement(list, 0, list.size() - 1, 10));
    }

    @Test
    public void testFindMaxSmallerElement2() {
        ArrayList<Integer> list = new ArrayList<>(Arrays.asList(1, 1, 2));

        assertEquals(Integer.valueOf(2), problem1.findMaxSmallerElement(list, 0, list.size() - 1, 3));
        assertEquals(Integer.valueOf(2), problem1.findMaxSmallerElement(list, 0, list.size() - 1, 4));
        assertEquals(Integer.valueOf(1), problem1.findMaxSmallerElement(list, 0, list.size() - 2, 4));
    }

    @Test
    public void testSolve() {
        int n = 3, m = 2;
        ArrayList<Integer> b = new ArrayList<>();
        ArrayList<Integer> g = new ArrayList<>();
        Collections.addAll(b, 1, 2, 1);
        Collections.addAll(g, 3, 4);

        assertEquals(12, problem1.solve(n, m, b, g));
    }
}
