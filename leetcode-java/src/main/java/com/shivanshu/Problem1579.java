package com.shivanshu;

class UnionFind {
    int[] parent;

    public UnionFind(UnionFind uf) {
        this.parent = uf.parent.clone();
    }

    public UnionFind(int n) {
        parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    public boolean union(int x, int y) {
        int parentx = find(x);
        int parenty = find(y);
        if (parentx == parenty) return false;
        parent[parentx] = parenty;
        return true;
    }

    public int find(int x) {
        return parent[x] = (x == parent[x] ? x : find(parent[x]));
    }
}

public class Problem1579 {

    public int maxNumEdgesToRemove(int n, int[][] edges) {
        UnionFind uf = new UnionFind(n + 1);
        int red_edges = 0, blue_edges = 0, ans = 0;

        for (int[] edge : edges) {
            if (edge[0] == 3) {
                // type 3
                if (uf.union(edge[1], edge[2])) {
                    red_edges++;
                    blue_edges++;
                } else {
                    ans++;
                }
            }
        }

        UnionFind blue_uf = new UnionFind(uf);
        UnionFind red_uf = new UnionFind(uf);

        for (int[] edge : edges) {
            if (edge[0] == 1) {
                // red
                if (red_uf.union(edge[1], edge[2])) {
                    red_edges++;
                } else {
                    ans++;
                }
            } else if (edge[0] == 2) {
                // blue
                if (blue_uf.union(edge[1], edge[2])) {
                    blue_edges++;
                } else {
                    ans++;
                }
            }
        }
        return (blue_edges == n - 1 && red_edges == n - 1) ? ans : -1;
    }

    public static void main(String[] args) {
        {
            Problem1579 p = new Problem1579();
            int n = 4;
            int[][] edges = {{3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4}};
            System.out.println(p.maxNumEdgesToRemove(n, edges));
        }
    }
}
