#include <bits/stdc++.h>

#define MOD (1000000007)
#define EPS (1e-9)
#define INF (2117117117)
#define LLINF (2117117117117117117LL)
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define sqr(a) ((a) * (a))
#define sz(a) ((int)(a).size())
const double PI = acos(-1.0);

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef unsigned int uint;
typedef long long llong;
typedef long double ldouble;
typedef unsigned long long ullong;

#define TASK "task"

using namespace std;

struct Tree {
    int m, d;
    Tree *L, *R;
    Tree(int _m) : m(_m), d(0), L(0), R(0) {}
};

void push(Tree* T) {
    T->m = max(T->m, T->d);
    if (T->L)
        T->L->d = max(T->L->d, T->d);
    if (T->R)
        T->R->d = max(T->R->d, T->d);
}

int get(Tree* T, int tl, int tr, int i) {
    push(T);
    int tx = (tl + tr) >> 1;
    if (T->L && i < tx)
        return max(get(T->L, tl, tx, i), T->m);
    if (T->R && i >= tx)
        return max(get(T->R, tx, tr, i), T->m);
    return T->m;
}

void upd(Tree* T, int tl, int tr, int l, int r, int d) {
    push(T);
    if (r <= tl || tr <= l)
        return;
    if (l <= tl && tr <= r) {
        T->d = d;
        return;
    }
    if (!T->L) {
        T->L = new Tree(T->m);
        T->R = new Tree(T->m);
    }
    int tx = (tl + tr) >> 1;
    upd(T->L, tl, tx, l, r, d);
    upd(T->R, tx, tr, l, r, d);
}

int n, q, x, y, z;
char c;
Tree *tv, *th;

int main() {
#ifdef lordf
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
#endif

    scanf("%d %d", &n, &q);
    tv = new Tree(0);
    th = new Tree(0);

    for (int qq = 0; qq < q; qq++) {
        scanf("%d %d %c", &x, &y, &c);
        if (c == 'U') {
            z = get(tv, 1, n + 1, x);
            printf("%d\n", y - z);
            upd(th, 1, n + 1, z + 1, y + 1, x);
            upd(tv, 1, n + 1, x, x + 1, y);
        } else {
            z = get(th, 1, n + 1, y);
            printf("%d\n", x - z);
            upd(tv, 1, n + 1, z + 1, x + 1, y);
            upd(th, 1, n + 1, y, y + 1, x);
        }
    }

    return 0;
}