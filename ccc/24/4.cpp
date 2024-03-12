#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>

const int MAX = 200001;
bool vis[MAX];
char col[MAX];
vector<vector<pi>> adj(MAX);

void dfs(int u, int c) {
  vis[u] = true;
  for (pi x : adj[u]) {
    if (!vis[x.first]) {
      col[x.second] = c ? 'R' : 'B';
      dfs(x.first, c ^ 1);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].emplace_back(b, i);
    adj[b].emplace_back(a, i);
    col[i] = 'G';
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i]) dfs(i, 0);
  }
  for (int i = 0; i < m; i++) {
    cout << col[i];
  }
  cout << '\n';
}
