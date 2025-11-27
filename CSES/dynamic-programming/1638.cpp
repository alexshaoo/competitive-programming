#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> grid(n);
  vector<vector<ll>> dp(n, vector<ll>(n, 0));
  for (int i = 0; i < n; ++i)
    cin >> grid[i];
  dp[0][0] = grid[0][0] == '.';
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] == '*')
        continue;
      if (r < n - 1 && grid[r + 1][c] == '.')
        dp[r + 1][c] = (dp[r + 1][c] + dp[r][c]) % MOD;
      if (c < n - 1 && grid[r][c + 1] == '.')
        dp[r][c + 1] = (dp[r][c + 1] + dp[r][c]) % MOD;
    }
  }
  cout << dp[n - 1][n - 1] << '\n';
}
