#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<vector<int>> adj;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    adj = vector<vector<int>>(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    return 0;
}