#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

const int MOD = 1e9 + 7;
const vector<int> delta = {-1, 0, -1};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  for (auto &xx : x)
    cin >> xx;
  vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));
  int first = x[0];
  if (first == 0) {
    for (int i = 0; i <= m; ++i)
      dp[0][i] = 1;
  } else {
    dp[0][first] = 1;
  }
  for (int i = 1; i < n; ++i) {
    int val = x[i];
    if (val == 0) {
      for (int j = 1; j <= m; ++j) {
        for (int k : {j - 1, j, j + 1}) {
          if (k >= 1 && k <= m)
            dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
        }
      }
    } else {
      for (int k : {val - 1, val, val + 1}) {
        if (k >= 1 && k <= m)
          dp[i][val] = (dp[i][val] + dp[i - 1][k]) % MOD;
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= m; ++i)
    ans = (ans + dp[n - 1][i]) % MOD;
  cout << ans << '\n';
}
