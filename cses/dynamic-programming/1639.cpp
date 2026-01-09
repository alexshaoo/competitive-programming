#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

const int MAXN = 5 * 1e3 + 5;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string a, b;
  cin >> a;
  cin >> b;
  int n = a.length(), m = b.length();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (i == 0) {
        dp[i][j] = j;
        continue;
      }
      if (j == 0) {
        dp[i][j] = i;
        continue;
      }
      int add = dp[i][j - 1] + 1;
      int remove = dp[i - 1][j] + 1;
      int replace = dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]);
      dp[i][j] = min(add, min(remove, replace));
    }
  }
  cout << dp[n][m] << '\n';
}
