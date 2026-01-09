#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

using State = tuple<ll, int, int>;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c}); // u -> {v, cost}
  }
  vector<vector<ll>> dp(n + 1, vector<ll>(2, LLONG_MAX));
  priority_queue<State, vector<State>, greater<State>>
      pq; // {cost, u, 1 if used coupon}
  pq.push({0LL, 1, 0});
  while (!pq.empty()) {
    auto [c, u, used] = pq.top();
    pq.pop();
    if (c > dp[u][used])
      continue;
    for (const auto &nxt : adj[u]) {
      auto [v, nc] = nxt;
      if (!used) {
        ll vcost = c + nc / 2;
        if (vcost < dp[v][1]) {
          dp[v][1] = vcost;
          pq.push({vcost, v, 1});
        }
      }
      ll vcost = c + nc;
      if (vcost < dp[v][used]) {
        dp[v][used] = vcost;
        pq.push({vcost, v, used});
      }
    }
  }
  cout << dp[n][1] << '\n';
}
