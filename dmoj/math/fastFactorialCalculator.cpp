#include <bits/stdc++.h>

using namespace std;

int main() {
    
    const unsigned long long MOD = 4294967295;
    
    unsigned long long N, n;
    unsigned long long f[34];

    scanf("%llu", &N);
    f[0] = 1;

    for (int i = 1; i < 34; ++i) f[i] = (i * f[i - 1]) & MOD;

    while (N--) {
        scanf("%llu", &n);
        printf("%llu\n", n > 33 ? 0 : f[n]);
    }
}