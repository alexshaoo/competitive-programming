#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int f(int x, int a, int b, int c) { return (int)(((ll)a * x + (ll)b) % c); }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int x, a, b, c;
  cin >> x >> a >> b >> c;
  ll sm = 0, xl = x, xr = 0;
  for (int i = 0; i < k; ++i) {
    if (i == 0)
      xr = x;
    else
      xr = f(xr, a, b, c);
    sm += xr;
  }
  ll res = sm;
  for (int l = 0, r = k - 1; r < n; ++l, ++r) {
    cout << sm << '\n';
    xr = f(xr, a, b, c);
    sm += xr;
    sm -= xl;
    xl = f(xl, a, b, c);
    res ^= sm;
  }
  cout << res << '\n';
  return 0;
}
