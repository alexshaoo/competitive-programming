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
  vector<int> coins(n);
  for (int i = 0; i < n; ++i) {
    cin >> coins[i];
  }
  sort(all(coins));
  // first i coins, cur val
  vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
  dp[0][0] = 1;
  for (int i = 0; i <= n; ++i) {
    for (int sum = 0; sum <= x; ++sum) {
      if (i > 0) {
        dp[i][sum] = (dp[i][sum] + dp[i - 1][sum]) % MOD;
        if (sum - coins[i - 1] >= 0) {
          dp[i][sum] = (dp[i][sum] + dp[i][sum - coins[i - 1]]) % MOD;
        }
      }
    }
  }
  cout << dp[n][x] << '\n';
}
