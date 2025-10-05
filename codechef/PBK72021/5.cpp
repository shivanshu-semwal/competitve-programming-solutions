#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n - i - 1; j++) {
                cout << " ";
            }
            char c = 'A';
            for (int j = 0; j <= i; j++) {
                cout << c;
                c++;
            }
            for (int j = 0; j <= i; j++) {
                cout << j + 1;
            }
            cout << "\n";
        }
    }
    return 0;
}