#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

const int MIN = -1e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<int> indeg(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    indeg[v]++;
  }
  vector<int> tmp, topOrder;
  for (int u = 1; u <= n; ++u)
    if (indeg[u] == 0)
      tmp.push_back(u);
  while (!tmp.empty()) {
    int u = tmp.back();
    tmp.pop_back();
    for (int v : adj[u]) {
      indeg[v]--;
      if (indeg[v] == 0)
        tmp.push_back(v);
    }
    topOrder.push_back(u);
  }
  vector<int> dp(n + 1, MIN), par(n + 1, -1);
  dp[1] = 1;
  for (int u : topOrder) {
    if (dp[u] != MIN) {
      for (int v : adj[u]) {
        if (dp[v] < dp[u] + 1) {
          dp[v] = dp[u] + 1;
          par[v] = u;
        }
      }
    }
  }
  if (dp[n] == MIN) {
    cout << "IMPOSSIBLE" << '\n';
    return 0;
  }
  vector<int> revOrder = {n};
  int curr = n;
  while (curr != 1) {
    curr = par[curr];
    revOrder.push_back(curr);
  }
  reverse(all(revOrder));
  cout << revOrder.size() << '\n';
  for (int u : revOrder)
    cout << u << ' ';
  cout << '\n';
}
