#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        // long long int b;
        string s;
        cin >> n;
        char *ch = (char *)malloc(sizeof(char) * (n + 1));
        // cin >> b;
        cin >> s;

        int a = s[0];
        ch[0] = 1;
        for (int i = 0; i < n; i++) {
            a = s[0] + ch[i];
        }
    }
    return 0;
}