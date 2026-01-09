#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int sm = n * (n + 1) / 2;
  if (sm % 2 != 0) {
    cout << 0 << '\n';
    return 0;
  }
  int target = sm / 2;
  // dp[x][i] = # number of ways to make sum x using numbers 1 .. i
  vector<vector<int>> dp(target + 1, vector<int>(n, 0));
  dp[0][0] = 1;
  for (int x = 0; x <= target; ++x) {
    for (int i = 1; i < n; ++i) {
      // don't use
      dp[x][i] = dp[x][i - 1];
      // use
      if (x - i >= 0)
        dp[x][i] = (dp[x][i] + dp[x - i][i - 1]) % MOD;
    }
  }
  cout << dp[target][n - 1] << '\n';
}
