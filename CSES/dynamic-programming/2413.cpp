#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // dp[i][0] = # towers given top is 2 1x1s
  // dp[i][1] = # towers given top is 1x2
  vector<vector<ll>> dp(MAXN, vector<ll>(2, 0));
  dp[1][0] = 1;
  dp[1][1] = 1;
  for (int i = 2; i < MAXN; ++i) {
    dp[i][0] = (4 * dp[i - 1][0] + dp[i - 1][1]) % MOD;
    dp[i][1] = (dp[i - 1][0] + 2 * dp[i - 1][1]) % MOD;
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
  }
}
