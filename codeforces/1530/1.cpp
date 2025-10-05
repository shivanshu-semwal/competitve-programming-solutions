#include <bits/stdc++.h>
#define lli long long int

using namespace std;

void print_vec(vector<int> v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    lli t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<int> v;
        for (int i = 0; i < s.length(); i++) {
            v.push_back(s[i] - '0');
        }

        lli counter = 0;
        while (1) {
            // print_vec(v);
            int min = 10;
            for (int i = 0; i < v.size(); i++) {
                if (v[i] < min && v[i] > 0) {
                    min = v[i];
                }
            }
            if (min == 10) {
                break;
            }
            for (int i = 0; i < v.size(); i++) {
                v[i] -= min;
            }
            counter += min;
            // cout << "min:: " << min;
        }
        cout << counter << "\n";
    }
    return 0;
}