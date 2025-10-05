#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        string s;
        cin >> s;
        int n = s.length();
        int count0 = 0, count1 = 0;

        for (auto i : s)
            if (i == '0')
                count0++;
            else
                count1++;

        if (count0 > count1) {
            for (int i = 0; i < count0; i++) cout << "0";
            cout << endl;
        } else if (count0 < count1) {
            for (int i = 0; i < count1; i++) cout << "1";
            cout << endl;
        } else {
            for (int i = 0; i < count1; i++) cout << "1";
            cout << endl;
        }
    }
    return 0;
}