#include <bits/stdc++.h>

typedef long long ll;
const ll MAXDIFF = 20000001;
const ll MAXPRIMES = 100001;
bool primes[MAXPRIMES], sieve[MAXDIFF];
ll n, m;

int main() {
	scanf("%lld %lld", &n, &m);
	
	ll comb = 0;
	
	std::fill_n(primes, MAXPRIMES, 1);
	
	if (n == 1) sieve[0] = 1;
	
	for (ll i = 2; i < MAXPRIMES; ++i) {
		if (primes[i]) {
			ll left;
			
			for (ll j = i * i; j < MAXPRIMES; j += i) primes[j] = 0;
			
			if (n % i == 0) left = n;
			else left = n + i - (n % i);
			
			// sieving the interval needed
			for (ll j = left; j < m; j += i) sieve[j-n] = 1;
			if (n <= i && i < m) sieve[i-n] = 0;
		}
	}
	
	for (ll j = n; j < m; j++) if (!sieve[j-n]) ++comb;
	
	printf("%lld\n", comb);
}
