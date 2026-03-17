#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> ways(n + 1);
  vector<int> indeg(n + 1);
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    indeg[v]++;
  }
  ways[1] = 1;
  queue<int> q;
  for (int u = 1; u <= n; ++u) {
    if (indeg[u] == 0) {
      q.push(u);
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      ways[v] = (ways[v] + ways[u]) % MOD;
      indeg[v]--;
      if (indeg[v] == 0)
        q.push(v);
    }
  }
  cout << ways[n] << '\n';
}
