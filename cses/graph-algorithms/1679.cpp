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
  vector<int> indeg(n + 1, 0);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    indeg[v]++;
  }
  vector<int> order;
  vector<bool> vis(n + 1, false);
  queue<int> q;
  for (int i = 1; i <= n; ++i)
    if (indeg[i] == 0)
      q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (vis[u])
      continue;
    order.push_back(u);
    vis[u] = true;
    for (int v : adj[u]) {
      indeg[v]--;
      if (!vis[v] && indeg[v] == 0)
        q.push(v);
    }
  }
  if (sz(order) != n) {
    cout << "IMPOSSIBLE" << '\n';
    return 0;
  }
  for (int u : order)
    cout << u << ' ';
}
