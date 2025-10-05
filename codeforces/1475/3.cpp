#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, k;
        cin >> a >> b >> k;
        vector<int> aa;
        vector<int> bb;
        for (int i = 0; i < k; i++) {
            int temp;
            cin >> temp;
            aa.push_back(temp);
        }
        for (int i = 0; i < k; i++) {
            int temp;
            cin >> temp;
            bb.push_back(temp);
        }
        int count = 0;
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                if (aa[i] != aa[j]) {
                    if (bb[i] != bb[j]) {
                        count++;
                    }
                }
            }
        }
        cout << count << '\n';
    }

    return 0;
}