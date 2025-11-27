#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  vector<vector<int>> dp(a + 1, vector<int>(b + 1, INT_MAX));
  for (int i = 1; i <= a; ++i) {
    for (int j = 1; j <= b; ++j) {
      if (i == j)
        dp[i][j] = 0;
      else {
        for (int r = 1; r < i; ++r) {
          dp[i][j] = min(dp[i][j], 1 + dp[r][j] + dp[i - r][j]);
        }
        for (int c = 1; c < j; ++c) {
          dp[i][j] = min(dp[i][j], 1 + dp[i][c] + dp[i][j - c]);
        }
      }
    }
  }
  cout << dp[a][b] << '\n';
}
