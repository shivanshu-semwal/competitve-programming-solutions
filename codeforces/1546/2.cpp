#include <cstdio>
int ans[100002], n, m, i, j, t;
char s[100002];
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (i = 0; i <= m; i++) ans[i] = 0;
        for (i = 1; i <= n * 2 - 1; i++) {
            scanf("%s", s);
            for (j = 0; j < m; j++) ans[j] ^= s[j];
        }
        for (i = 0; i < m; i++) putchar(ans[i]);
        puts("");
    }
}