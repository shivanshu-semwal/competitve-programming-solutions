#include <limits.h>
#include <stdio.h>

int main() {
    // int a = -13 % 2;
    int res = 0;
    int x = -123;
    while (x) {
        if (res > INT_MAX / 10 || res < INT_MIN / 10)
            return 0;
        res = res * 10 + x % 10;
        printf("%d %d\n", res, x%10);

        x /= 10;
    }
    printf("%d", res);
    return 0;
}