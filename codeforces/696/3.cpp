#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void isValid(vector<int> a, int n) {
    vector<bool> c(n, false);
    vector<int> ans;
    ans.push_back(n);
    for (int i = a.size() - 1; i >= 0; i--) {

    }
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> a;
        int temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            a.push_back(temp);
        }
        sort(a.begin(), a.end());

        bool flag = true;

        int size = a.size();
        int start = a[size - 1] + a[size - 2];
        int stop = a[size - 1] + a[0];

        for (int i = start; i > stop; i--) {
            isValid(a, i);
        }
    }
    return 0;
}