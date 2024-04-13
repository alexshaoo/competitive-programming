#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MXN = 1e5;
const int MOD = 1e9 + 7;

void solve(ll n) {
  ll p[20];
  ll s = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    s += p[i];
  }
  for (int i = 0; i < 1 << n; ++i) {
    ll cs = 0;
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) cs += p[i];
    }
    // cout << s / 2 << " " << cs << '\n';
    if (cs <= s / 2) ans = max(ans, cs);
  }
  cout << abs(2 * ans - s) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  solve(n);
}
