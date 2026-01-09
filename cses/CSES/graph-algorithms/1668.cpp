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
  vector<int> team(n + 1, 0);
  vector<bool> vis(n + 1, false);
  queue<int> q;
  for (int pupil = 1; pupil <= n; ++pupil) {
    if (vis[pupil])
      continue;
    team[pupil] = 1;
    q.push(pupil);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (vis[u])
        continue;
      vis[u] = true;
      for (int v : adj[u]) {
        if (team[u] == team[v]) {
          cout << "IMPOSSIBLE" << '\n';
          return 0;
        }
        team[v] = team[u] % 2 + 1;
        q.push(v);
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    cout << team[i] << ' ';
}
