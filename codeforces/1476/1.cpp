#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n, k;
        long long int ans;
        cin >> n >> k;
        if (n == k) {
            cout << "1\n";
        } else if (n < k) {
            ans = k - (k / n) * (n - 1);
            cout << ans << '\n';
        } else {
            k = k * ceil(n / k);
            if (n == k) {
                cout << "1\n";
            } else {
                ans = k - (k / n) * (n - 1);
                cout << ans << '\n';
            }
        }
    }
    return 0;
}