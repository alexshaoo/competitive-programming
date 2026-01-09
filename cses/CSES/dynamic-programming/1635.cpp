#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  int coins[n];
  for (int i = 0; i < n; ++i) {
    cin >> coins[i];
  }
  vector<ll> dp(x + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= x; ++i) {
    for (int coin : coins) {
      if (i - coin >= 0 && dp[i - coin] != -1) {
        dp[i] = (dp[i] + dp[i - coin]) % MOD;
      }
    }
  }
  cout << dp[x] << '\n';
}
