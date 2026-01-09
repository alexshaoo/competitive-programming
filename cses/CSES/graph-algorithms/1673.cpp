#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

const ll mn = LLONG_MIN;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> edges(m);
  vector<vector<int>> revEdges(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[i] = {u, v, w};
    revEdges[v].push_back(u);
  }
  vector<ll> score(n + 1, mn);
  score[1] = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (const auto &edge : edges) {
      auto [u, v, w] = edge;
      if (score[u] != mn && score[v] < score[u] + w) {
        score[v] = score[u] + w;
      }
    }
  }
  unordered_set<int> canReachEnd;
  vector<bool> vis(n + 1, false);
  vector<int> q;
  q.push_back(n);
  while (!q.empty()) {
    int u = q.back();
    q.pop_back();
    if (vis[u])
      continue;
    canReachEnd.insert(u);
    vis[u] = true;
    for (int v : revEdges[u]) {
      if (!vis[v])
        q.push_back(v);
    }
  }
  // if dist can be improved, infinite loop
  for (const auto &edge : edges) {
    auto [u, v, w] = edge;
    if (score[u] != mn && score[v] < score[u] + w && canReachEnd.count(v)) {
      cout << -1 << '\n';
      return 0;
    }
  }
  cout << score[n] << '\n';
  return 0;
}
