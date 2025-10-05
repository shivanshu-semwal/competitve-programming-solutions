#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        ll min = 0;
        ll no8 = 0;
        ll no6 = n / 6;
        ll no10 = 0;
        if (n < 6) {
            min = 15;
        }
        else if (n == no6 * 6) {
            min = no6 * 15;
        } else {
            ll temp = n - no6 * 6 + 6;
            // cout << "TEMP: " << temp << "\n";
            if(temp == 11){
                no6++;
                min = no6 * 15;
            }
            else if (temp == 8 || temp == 7) {
                no8 = 1;
                min = (no6 - 1) * 15 + no8 * 20;
            } else {
                no10 = 1;
                min = (no6 - 1) * 15 + no10 * 25;
            }
        }
        // cout << "6: " << no6 << " 8: " << no8 << " 10: " << no10 << " ";
        cout << min << "\n";
    }

    return 0;
}