#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main() {
    lli t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        if(n % 10 == 9) n++;
        lli ans = n/10;
        cout << ans << "\n";
    }
    return 0;
}