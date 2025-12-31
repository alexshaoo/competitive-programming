#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int l = -1, r = -1;

void dfs(vector<vector<int>> &adj, vector<int> &vis, vector<int> &par, int u) {
  vis[u] = 1;
  for (int v : adj[u]) {
    if (l != -1)
      return;
    if (vis[v] == 1) { // found
      l = v;
      r = u;
      return;
    } else if (vis[v] == 0) { // unexplored
      par[v] = u;
      dfs(adj, vis, par, v);
      if (l != -1)
        return;
    }
  }
  vis[u] = 2;
}

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
  }
  vector<int> q;
  vector<int> vis(n + 1, 0);
  vector<int> par(n + 1, 0);
  for (int u = 1; u <= n; ++u) {
    dfs(adj, vis, par, u);
    if (l != -1)
      break;
  }
  if (l == -1) {
    cout << "IMPOSSIBLE" << '\n';
    return 0;
  }
  vector<int> cycle = {l};
  for (int tmp = r; tmp != l; tmp = par[tmp]) {
    cycle.push_back(tmp);
  }
  cycle.push_back(l);
  reverse(all(cycle));
  cout << sz(cycle) << '\n';
  for (int u : cycle)
    cout << u << ' ';
  cout << '\n';
}
