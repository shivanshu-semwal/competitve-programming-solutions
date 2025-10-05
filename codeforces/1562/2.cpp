#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool isPrime(int n) {
    // prime no array
    int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23,
               29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
               71, 73, 79, 83, 89, 97, 101, 103, 107, 109,
               113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
               173, 179, 181, 191, 193, 197, 199, 211, 223, 227,
               229, 233, 239, 241, 251, 257, 263, 269, 271, 277,
               281, 283, 293, 307, 311, 313, 317, 331, 337, 347,
               349, 353, 359, 367, 373, 379, 383, 389, 397, 401,
               409, 419, 421, 431, 433, 439, 443, 449, 457, 461,
               463, 467, 479, 487, 491, 499, 503, 509, 521, 523,
               541, 547, 557, 563, 569, 571, 577, 587, 593, 599,
               601, 607, 613, 617, 619, 631, 641, 643, 647, 653,
               659, 661, 673, 677, 683, 691, 701, 709, 719, 727,
               733, 739, 743, 751, 757, 761, 769, 773, 787, 797,
               809, 811, 821, 823, 827, 829, 839, 853, 857, 859,
               863, 877, 881, 883, 887, 907, 911, 919, 929, 937,
               941, 947, 953, 967, 971, 977, 983, 991, 997};
    int start = p[0];
    for (int i = 0; start * start <= n; i++) {
        if (n % start == 0) return false;
        start = p[i];
    }
    return true;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n;
        cin >> s;
        vector<int> d(n);
        for (int i = 0; i < s.length(); i++) {
            d[i] = s[i] - '0';
        }
        bool one = false;
        for (int i = 0; i < n; i++) {
            if (d[i] == 1 || d[i] == 4 || d[i] == 6 || d[i] == 8 || d[i] == 9) {
                cout << "1\n";
                cout << d[i] << "\n";
                one = true;
                break;
            }
        }
        if (one) continue;

        // check for two digit
        bool two = false;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int no = d[i] * 10 + d[j];
                if (!isPrime(no)) {
                    two = true;
                    cout << "2\n";
                    cout << no << "\n";
                    break;
                }
            }
            if (two) break;
        }
        if (two) continue;

        // check for 3 digit
        bool three = false;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; j++) {
                    int no = d[i] * 100 + d[j] * 10 + d[k];
                    if (!isPrime(no)) {
                        three = true;
                        cout << "3\n";
                        cout << no << "\n";
                        break;
                    }
                }
                if (three) break;
            }
            if (three) break;
        }
        if (three) continue;
    }
    return 0;
}