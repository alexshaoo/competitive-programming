#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MXN = 1e5;
const int MOD = 1e9 + 7;

void solve(ll n) {
  ll p = 5;
  ll ans = 0;
  while (p <= n) {
    for (int i = p; i <= n; i += p) ++ans;
    p *= 5;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  solve(n);
}