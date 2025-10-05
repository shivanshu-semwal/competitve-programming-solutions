// https://codeforces.com/contest/1542/problem/C

#include <bits/stdc++.h>

#define lli long long int
#define modd 1000000007l
using namespace std;

lli lcm(lli a, lli b) {
    lli l = a * b / __gcd(a, b);
    return l;
}

int main() {
    lli t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;

        lli sum = 0;
        lli lcm1 = 1, lcm2 = 1;

        for (int i = 2; i <= 42 && i <= n; i++) {
            lcm1 = lcm2;
            lcm2 = lcm(lcm2, i);
            lli temp = (n / lcm1) - (n / lcm2);
            sum = (sum + ((i * temp) % modd)) % modd;
        }
        if(n==1) sum = 2;
        else if(n==2) sum = 5;
        cout << sum << "\n";
    }
    return 0;
}