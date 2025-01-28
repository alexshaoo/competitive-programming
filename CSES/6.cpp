#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MXN = 1e4 + 5;

void solve(ll n) {
  for (ll i = 1; i <= n; ++i) {
    ll squares = i * i;
    ll ans = squares * (squares - 1) / 2;
    if (i > 2) ans -= 4 * (i - 1) * (i - 2);
    cout << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  solve(n);
}
