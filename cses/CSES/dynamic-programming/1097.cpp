#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> x(n);
  ll sm = 0;
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
    sm += x[i];
  }
  vector<vector<ll>> dp(n, vector<ll>(n, 0));
  for (int l = n - 1; l >= 0; --l) {
    for (int r = l; r < n; ++r) {
      if (l == r)
        dp[l][r] = x[l];
      else {
        dp[l][r] = max(x[l] - dp[l + 1][r], x[r] - dp[l][r - 1]);
      }
    }
  }
  cout << (sm + dp[0][n - 1]) / 2 << '\n';
}
