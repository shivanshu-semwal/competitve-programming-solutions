#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        
        long long n, x;
        cin >> n;
        
        vector<long long> a;
        vector<long long> b;
        
        for (int i = 0; i < n; i++) {
            cin >> x;
            //cout<<x<<endl;
            a.push_back(x);
        }
        for (int i = 0; i < n; i++) {
            cin >> x;
            b.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        long long h = 0, v = 0;
        
        for (int i = a.size() / 4; i < a.size(); i++) {
            // cout<<ans[i]<<" "<<bans[i]<<endl;
            h += a[i];
            v += b[i];
        }
        if (h >= v) {
            cout << 0 << endl;
            continue;
        }
        long long l = 0, r = n, res = n;
        while (l <= r) {

            long long mid = (l + r) / 2;
            // cout<<mid<<endl;
            vector<long long> ans;
            vector<long long> bans;
            long long s1 = 0, s2 = 0;
            for (int i = 0; i < n; i++) {
                ans.push_back(a[i]);
            }
            for (int i = 0; i <= mid; i++) {
                ans.push_back(100);
                bans.push_back(0);
            }
            for (int i = 0; i < n; i++) {
                bans.push_back(b[i]);
            }
            for (int i = ans.size() / 4; i < ans.size(); i++) {
                // cout<<ans[i]<<" "<<bans[i]<<endl;
                s1 += ans[i];
                s2 += bans[i];
            }
            if (s1 >= s2) {
                res = min(res, mid + 1);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << res << endl;
    }
    return 0;
}
