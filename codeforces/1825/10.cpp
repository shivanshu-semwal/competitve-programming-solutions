#include <bits/stdc++.h>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

int T, n, m, a[N], buc[N];
template <typename T> void chkmin(T& x, T y) {
    if (x > y)
        x = y;
}
template <typename T> void chkmax(T& x, T y) {
    if (x < y)
        x = y;
}

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = (1); i <= (n); i++)
        scanf("%d", &a[i]);

    int cntL = 0, cntR = 0;
    for (int i = (1); i <= (n); i++) {
        if (a[i] == -1)
            ++cntL;
        else if (a[i] == -2)
            ++cntR;
        else
            ++buc[a[i]];
    }
    int nowL = 0, nowR = 0, vis = 0;
    for (int i = (1); i <= (m); i++) {
        if (buc[i])
            ++vis;
        else
            ++nowR;
    }
    int ans = max(cntL, cntR) + vis;
    for (int i = (1); i <= (m); i++) {
        if (buc[i]) {
            int leftused = min(cntL, nowL);
            int rightused = min(cntR, nowR);
            int total = vis + leftused + rightused;
            if (total > ans)
                ans = total;
        } else {
            nowL += 1;
            nowR -= 1;
        }
    }
    if (ans > m)
        ans = m;
    printf("%d\n", ans);

    for (int i = (1); i <= (m); i++)
        buc[i] = 0;
}

int main() {
    for (scanf("%d", &T); T; T--)
        solve();
    return 0;
}