#include <stdio.h>

// checks if a number is prime range 1-40,000
int isPrime(int n) {
    //check if a no if prime
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};

    int len = sizeof primes / sizeof primes[0];

    for (int i = 0; i < len && primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            return 0;
        }
    }

    return 1; // yes no is prime
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);

        int no1=0, no2=0;
        for(int i=1+n;;i++){
            if(isPrime(i)==1){
                no1=i;
                break;
            }
        }
        for(int i=no1+n;;i++){
            if(isPrime(i)==1){
                no2=i;
                break;
            }
        }
        long long int ans = no1 * no2;
        printf("%lld\n", ans);
    }
    return 0;
}