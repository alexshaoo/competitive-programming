#include <bits/stdc++.h>

typedef long long ll;
const ll MAXN = 1000001;
bool primes[MAXN];
ll N, a, b;

int main() {
	scanf("%lld",&N);
	
	std::fill_n(primes, MAXN, 1);
	
	// generate sieve
	primes[0] = 0;
	primes[1] = 0;
	
	for (ll i = 2; i < MAXN; ++i) {
		if (primes[i]) {
			for (ll j = i*i; j < MAXN; j += i) {
				primes[j] = 0;
			}
		}	
	}
	
	for (ll i = 0; i < N; ++i) {
		ll stones = 0;
		scanf("%lld %lld", &a, &b);
		for (ll j = a; j < b; ++j) {
			stones += primes[j];
		}
		printf("%lld\n", stones);
	}
}