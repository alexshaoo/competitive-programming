#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  deque<int> dq;
  vector<bool> vis(n + 1, false);
  vector<int> par(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    if (vis[i])
      continue;
    dq.push_back(i);
    while (!dq.empty()) {
      int u = dq.back();
      dq.pop_back();
      vis[u] = true;
      for (int v : adj[u]) {
        if (v == par[u])
          continue;
        if (vis[v]) {
          // found loop
          vector<int> loop = {v};
          while (u != v) {
            loop.push_back(u);
            u = par[u];
          }
          loop.push_back(v);
          cout << loop.size() << '\n';
          for (int v : loop)
            cout << v << ' ';
          return 0;
        }
        par[v] = u;
        dq.push_back(v);
      }
    }
  }
  cout << "IMPOSSIBLE" << '\n';
}
