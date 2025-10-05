#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        char a[n + 1];
        char b[n + 1];
        char c[n + 1];

        scanf("%s", a);

        for (int i = 0; i < n; i++) {
            a[i] = a[i] - '0';
        }

        b[0] = 1;
        c[0] = a[0] + b[0];

        int new = 0;
        int i;
        for (i = 1; i < n; i++) {
            if (c[i - 1] == 2) {
                if (a[i] == 1) {
                    b[i] = 0;
                } else {
                    b[i] = 1;
                }
            } else if (c[i - 1] == 1) {
                if (a[i] == 1) {
                    b[i] = 1;
                } else {
                    b[i] = 0;
                }
            } else {
                if (a[i] == 0) {
                    b[i] = 1;
                } else {
                    b[i] = 1;
                }
            }
            c[i] = a[i] + b[i];
        }
        b[i] = '\0';
        for (i = 0; i < n; i++) {
            b[i] = b[i] + '0';
        }
        printf("%s\n", b);
    }
    return 0;
}