#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a = 1;
        char c = 'A';
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                a = 1;
            else
                a = -1;
            for (int j = 0; j < n; j++) {
                if (a == 1) {
                    cout << "*";
                    a *= -1;
                } else {
                    cout << c;
                    c++;
                    a *= -1;
                }
            }
            cout << "\n";
        }
    }
    return 0;
}