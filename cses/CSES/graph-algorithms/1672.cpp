#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

const ll MX = 1e9 * 501;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, MX));
  for (int i = 1; i <= n; ++i)
    dp[i][i] = 0;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    dp[a][b] = min(dp[a][b], (ll)c);
    dp[b][a] = min(dp[b][a], (ll)c);
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << (dp[u][v] == MX ? -1 : dp[u][v]) << '\n';
  }
}
