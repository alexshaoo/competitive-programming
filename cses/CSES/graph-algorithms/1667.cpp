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
  vector<int> par(n + 1, -1);
  queue<int> q;
  q.push(1);
  vector<bool> vis(n + 1, false);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (vis[u])
      continue;
    vis[u] = true;
    if (u == n)
      break;
    for (int v : adj[u]) {
      q.push(v);
      if (par[v] == -1)
        par[v] = u;
    }
  }
  if (!vis[n]) {
    cout << "IMPOSSIBLE" << '\n';
    return 0;
  }
  int len = 1;
  int comp = n;
  vector<int> path = {n};
  while (comp != 1) {
    ++len;
    comp = par[comp];
    path.push_back(comp);
  }
  cout << len << '\n';
  for (int i = len - 1; i >= 0; --i)
    cout << path[i] << ' ';
}
