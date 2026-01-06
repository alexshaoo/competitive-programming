#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

using State = tuple<ll, int>;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n + 1), rev(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c}); // u -> {v, cost}
    rev[b].push_back({a, c});
  }
  vector<ll> forwardCost(n + 1), backwardCost(n + 1);
  vector<bool> vis(n + 1);
  priority_queue<State, vector<State>, greater<State>> pq; // {cost, u}
  pq.push({0LL, 1});
  while (!pq.empty()) {
    auto [c, u] = pq.top();
    pq.pop();
    if (vis[u])
      continue;
    vis[u] = true;
    forwardCost[u] = c;
    for (const auto &nxt : adj[u]) {
      auto [v, nc] = nxt;
      if (!vis[v])
        pq.push({c + nc, v});
    }
  }
  fill(all(vis), false);
  pq.push({0LL, n});
  while (!pq.empty()) {
    auto [c, u] = pq.top();
    pq.pop();
    if (vis[u])
      continue;
    vis[u] = true;
    backwardCost[u] = c;
    for (const auto &nxt : rev[u]) {
      auto [v, nc] = nxt;
      if (!vis[v])
        pq.push({c + nc, v});
    }
  }
  ll mn = LLONG_MAX;
  for (int u = 1; u <= n; ++u) {
    for (auto [v, c] : adj[u]) {
      mn = min(mn, forwardCost[u] + backwardCost[v] + c / 2);
    }
  }
  cout << mn << '\n';
}
