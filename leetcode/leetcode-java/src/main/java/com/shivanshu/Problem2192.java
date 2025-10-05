package com.shivanshu;

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class Problem2192 {

    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        // make adjacency list
       List<Integer>[] adjList = new ArrayList[n];
       for(int i=0;i<n;i++) adjList[i] = new ArrayList<>();

       // answer to return
       List<List<Integer>> ancestors = new ArrayList<>();
       for(int i=0;i<n;i++) ancestors.add(new ArrayList<>());

       for(int[] edge: edges){
           int from = edge[0];
           int to = edge[1];
           adjList[from].add(to);
       }

       for(int i=0;i<n;i++){
           dfs(i, adjList, i, ancestors);
       }

       return  ancestors;
    }

    private void dfs(int ancestor, List<Integer>[] adjList, int currentNode, List<List<Integer>> ancestors) {
        for(int childNode: adjList[currentNode]){
            if(ancestors.get(childNode).isEmpty() || ancestors.get(childNode).getLast() != ancestor){
                ancestors.get(childNode).add(ancestor);
                dfs(ancestor, adjList, childNode, ancestors);
            }
        }
    }

    public static void main(String[] args) {
        // test case 1
        {
            Problem2192 p = new Problem2192();
            int n = 8;
            int[][] edges = {{0, 3}, {0, 4}, {1, 3}, {2, 4}, {2, 7}, {3, 5}, {3, 6}, {3, 7}, {4, 6}};

            // output
            int[][] ans = {{}, {}, {}, {0, 1}, {0, 2}, {0, 1, 3}, {0, 1, 2, 3, 4}, {0, 1, 2, 3}};
            System.out.println(p.getAncestors(n, edges));
        }
        {
            Problem2192 p = new Problem2192();
            int n = 8;
            int[][] edges = {{0, 3}, {0, 4}, {1, 3}, {2, 4}, {2, 7}, {3, 5}, {3, 6}, {3, 7}, {4, 6}};

            // output
            int[][] ans = {{}, {}, {}, {0, 1}, {0, 2}, {0, 1, 3}, {0, 1, 2, 3, 4}, {0, 1, 2, 3}};
            System.out.println(p.getAncestors(n, edges));
        }
    }
}

