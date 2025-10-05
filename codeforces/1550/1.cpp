#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main() {
    lli t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        lli sum = 0;
        lli i;
        lli counter = 0;
        for (i = 1;;) {
            sum += i;
            counter++;
            if (sum > n) break;
            i += 2;
        }
        // cout << "sum: " << sum << " counter: " << counter << " i: " << i << "\n ";
        sum -= i;
        if (sum == n) {
            counter--;
            cout << counter << "\n";
        } else {
            cout << counter << "\n";
        }
    }
    return 0;
}