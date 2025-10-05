#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int a = 0;
    int b = 0;
    bool aWon = false;

    for (int i = 0; i < s.size(); i += 2) {
        if (s[i] == 'A') {
            a += s[i + 1] - '0';
        } else {
            b += s[i + 1] - '0';
        }
        if (a == 10 && b == 10) {
            // a = 0, b = 0;
            for (int j = i + 2; j < s.size(); j += 2) {
                
                if (s[j] == 'A') {
                    a += s[j + 1] - '0';
                } else {
                    b += s[j + 1] - '0';
                }
                if (abs(a - b) > 1) {
                    aWon = a > b;
                    break;
                }
            }
            break;
        }
        if (a > 10) {
            aWon = true;
            break;
        }
        if (b > 10) {
            aWon = false;
            break;
        }
    }
    if (aWon)
        cout << "A";
    else
        cout << "B";
    return 0;
}