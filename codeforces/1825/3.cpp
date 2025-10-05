#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> way;
    int one = 0, two = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == -1)
            one++;
        else if (t == -2)
            two++;
        else {
            way.push_back(t);
        }
    }
    sort(way.begin(), way.end());

    // remove duplicates
    int ways = (way.size() >= 1) ? 1 : 0;
    for (int i = 1; i < way.size(); i++) {
        if (way[i] != way[i - 1])
            way[ways++] = way[i];
    }

    for (int i = 0; i < ways; i++)
        cout << way[i] << " ";
    cout << endl;

    int ans = 0;
    int lefts = 0, rights = m;
    int leftend = 0;
    for (int i = 0; i < ways; i++) {
        if(way[i] < one){
            ans = way[i];
            one++;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}