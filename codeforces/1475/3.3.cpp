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

        map<int, vector<int>> lists;
        vector<vector<int>> list(a+1);

        for (int i = 0; i < k; i++) {
            lists.insert(aa[i], lists[aa[i]])
            list[aa[i]].push_back(bb[i]);
        }

        int count = 0;

        for (int i = 0; i <= a; i++) {
            if (!list[i].empty()) {                         // pick 1 boy
                for (int j = 0; j <= list[i].size(); j++) { // pick 1 girl
                    for (int k = i + 1; k <= a; k++) {      //pick 2 boy

                        bool flag = false;                         // is 2 girl same as 1 girl
                        for (int l = 0; j < list[k].size(); l++) { // pick 2 girl
                            if (list[k][l] == list[i][j]) {
                                flag = true;
                                break;
                            }
                        }
                        if (flag)
                            count += list[k].size() - 1;
                        else
                            count += list[k].size();
                    }
                }
            }
        }

        cout << count << "\n";
    }
    return 0;
}