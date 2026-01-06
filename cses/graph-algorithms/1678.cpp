#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
const int MAXN = 1e5 + 5, MAXM = 2e5 + 5;

vector<vector<int>> adj(MAXN);
vector<int> vis(MAXN, 0);
vector<int> par(MAXN, 0);
int l = -1, r = -1;

bool dfs(int u) {
  vis[u] = 1;
  for (int v : adj[u]) {
    if (vis[v] == 1) { // found
      l = v;
      r = u;
      return true;

    } else if (vis[v] == 0) { // unexplored
      par[v] = u;
      if (dfs(v))
        return true;
    }
  }
  vis[u] = 2;
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  for (int u = 1; u <= n; ++u) {
    if (!vis[u] && dfs(u))
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
}
