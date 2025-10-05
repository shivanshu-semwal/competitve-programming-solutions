#include <bits/stdc++.h>
#define ll long long int
#define vvi vector<vector<int>>
#define vi vector<int>
#define pb push_back

using namespace std;

void submain() {
    int n, m;
    int a, b;
    cin >> n >> m;
    vvi g(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    /// BFS
    queue<int> q;
    vi visited(n + 1);

    set<int> supreme;

    vvi scores(n + 1, vi(2, 0));
    
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 1) continue;
        q.push(i);
        visited[i] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vi score(2);
            for (auto x : g[u]) {
                if (!visited[x]) {
                    visited[x] = 1;
                    q.push(x);
                }
                if (x < u)
                    score[0]++;
                else
                    score[1]++;
            }
            scores[u][0] = score[0];
            scores[u][1] = score[1];
            if (score[1] == 0) supreme.insert(u);
        }
    }
    ///
    int qu, x;
    cin >> qu;
    while (qu--) {
        cin >> x;
        if (x == 3) {
            cout << supreme.size() << '\n';
        } else if (x == 1) {
            cin >> a >> b;
            // 2 3
            int mn = min(a, b);
            int mx = max(a, b);
            scores[mn][1]++;
            scores[mx][0]++;
            if (supreme.find(mn) != supreme.end()) {
                supreme.erase(mn);
            }
        } else {
            cin >> a >> b;
            int mn = min(a, b);
            int mx = max(a, b);
            scores[mn][1]--;
            scores[mx][0]--;
            if (scores[mn][1] == 0) {
                supreme.insert(mn);
            }
        }
    }
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        submain();
    }
    return 0;
}