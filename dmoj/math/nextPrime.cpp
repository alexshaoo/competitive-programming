// everyone used miller rabin ok
#pragma GCC optimize("O2")
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// https://github.com/kth-competitive-programming/kactl/blob/main/content/number-theory/ModMulLL.h

ull modmul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
        if (e & 1) ans = modmul(ans, b, mod);
    return ans;
}

// https://github.com/kth-competitive-programming/kactl/blob/main/content/number-theory/MillerRabin.h

bool isPrime(ull n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
        s = __builtin_ctzll(n-1), d = n >> s;
    for (ull a : A) {   // ^ count trailing zeroes
        ull p = modpow(a%n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N;
    cin >> N;

    while (!isPrime(N)) {
        ++N;
    }

    cout << N << "\n";
}