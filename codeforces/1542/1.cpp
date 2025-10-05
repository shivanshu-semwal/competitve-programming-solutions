#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main() {
    lli t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        n *= 2;
        lli temp;
        vector<lli> v;
        while (n-- && cin >> temp) {
            v.push_back(temp);
        }
        lli even = 0, odd = 0;
        for (lli i = 0; i < v.size(); i++) {
            if (v[i] % 2 == 0)
                even++;
            else
                odd++;
        }
        if (even == odd) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}