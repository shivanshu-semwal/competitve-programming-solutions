#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve() {
    ll W, H;
    cin >> W >> H;

    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    ll w, h;
    cin >> w >> h;

    // width of present box
    ll w1 = x2 - x1;
    ll h1 = y2 - y1;

    // if both boxes can fit
    if (w1 + w > W && h1 + h > H) {
        cout << "-1\n";
        return;
    }

    if (w1 + w <= W && h1 + h <= H) {
        // it can fit in both ways

        //horizontal
        ll horizontal = 0;
        if (x1 <= W - x2) {
            // left corner is near
            ll space = w - (W - x2);
            if (space > 0) {
                horizontal = space;
            } else {
                horizontal = 0;
            }
        } else {
            // right corner is near
            ll space = w - x1;
            if (space > 0) {
                horizontal = space;
            } else {
                horizontal = 0;
            }
        }

        // vertical
        ll vertical = 0;
        // it can fit in vertical dir
        if (y1 <= H - y2) {
            // bottom corner is near
            ll space = h - (H - y2);
            if (space > 0) {
                vertical = space;
            } else {
                vertical = 0;
            }
        } else {
            // right corner is near
            ll space = h - y1;
            if (space > 0) {
                vertical = space;
            } else {
                vertical = 0;
            }
        }

        if (vertical == 0 && horizontal == 0) {
            cout << "0\n";
            return;
        }
        if (vertical == 0) {
            cout << horizontal << "\n";
            return;
        }

        if (horizontal == 0) {
            cout << vertical << "\n";
            return;
        }

        if (vertical < horizontal) {
            cout << vertical << "\n";
            return;
        } else {
            cout << horizontal << "\n";
            return;
        }

    } else if (w1 + w <= W) {
        // it can fit in only horizontal
        if (x1 <= W - x2) {
            // left corner is near
            ll space = w - (W - x2);
            if (space > 0) {
                cout << space << "\n";
                return;
            } else {
                cout << "0\n";
                return;
            }
        } else {
            // right corner is near
            ll space = w - x1;
            if (space > 0) {
                cout << space << "\n";
                return;
            } else {
                cout << "0\n";
                return;
            }
        }
    } else if (h1 + h <= H) {
        // it can fit in vertical dir
        if (y1 <= H - y2) {
            // bottom corner is near
            ll space = h - (H - y2);
            if (space > 0) {
                cout << space << "\n";
                return;
            } else {
                cout << "0\n";
                return;
            }
        } else {
            // right corner is near
            ll space = h - y1;
            if (space > 0) {
                cout << space << "\n";
                return;
            } else {
                cout << "0\n";
                return;
            }
        }
    }
    return;
}

int main() {

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}