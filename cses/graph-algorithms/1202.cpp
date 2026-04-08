#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b, p;
    cin >> a >> b >> p;
    adj[a].push_back({b, p});
  }

  // min price, # min price routes, min # flights in min price route, max #
  // flights in min price route
  vector<array<ll, 4>> dp(n + 1, {LLONG_MAX, 0, LLONG_MAX, 0});
  dp[1] = {0, 1, 0, 0};
  using State = pair<ll, int>;
  priority_queue<State, vector<State>, greater<State>> pq;
  pq.push({0, 1});
  while (!pq.empty()) {
    auto [price, u] = pq.top();
    pq.pop();
    if (price > dp[u][0])
      continue;
    for (const auto &[v, currPrice] : adj[u]) {
      ll newPrice = price + (ll)currPrice;
      if (newPrice < dp[v][0]) {
        dp[v][0] = newPrice;
        dp[v][1] = dp[u][1];
        dp[v][2] = dp[u][2] + 1;
        dp[v][3] = dp[u][3] + 1;
        pq.push({newPrice, v});
      } else if (newPrice == dp[v][0]) {
        dp[v][1] = (dp[v][1] + dp[u][1]) % MOD;
        dp[v][2] = min(dp[v][2], dp[u][2] + 1);
        dp[v][3] = max(dp[v][3], dp[u][3] + 1);
      }
    }
  }
  cout << dp[n][0] << ' ' << dp[n][1] << ' ' << dp[n][2] << ' ' << dp[n][3]
       << '\n';
}
