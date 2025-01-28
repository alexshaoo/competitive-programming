#include <bits/stdc++.h>
using namespace std;

#define cl(a, b) memset(a, b, sizeof(a))
#define all(x) x.begin(),x.end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int mod = 1e9 + 7;

void mult(ull f[2][2], ull g[2][2]) {
  ull x = (f[0][0] * g[0][0]) % mod + (f[0][1] * g[1][0]) % mod;
  ull y = (f[0][0] * g[0][1]) % mod + (f[0][1] * g[1][1]) % mod;
  ull z = (f[1][0] * g[0][0]) % mod + (f[1][1] * g[1][0]) % mod;
  ull w = (f[1][0] * g[0][1]) % mod + (f[1][1] * g[1][1]) % mod;
  f[0][0] = x;
  f[0][1] = y;
  f[1][0] = z;
  f[1][1] = w;
}

void pow(ull f[2][2], ull n) {
  ull g[2][2] = {{1, 1}, {1, 0}};
  if (n > 1) {
		pow(f, n/2);
		mult(f, f);
		if (n % 2 == 1) mult(f, g);
  }
}

ull fib(ull n) {
  if (n <= 0) return 0;
  ull f[2][2] = {{1, 1}, {1, 0}};
  pow(f, n-1);
  return f[0][0] % mod;
}

int main() {
	int pisano = 2*(mod+1);
  ull n = 0;
  int c = 0;
  while (c < '0') c = getchar();
  while (c >= '0') {
		n = (n * 10 + c - '0') % pisano;
		c = getchar();
  }
  cout << fib(n);
  return 0;
}