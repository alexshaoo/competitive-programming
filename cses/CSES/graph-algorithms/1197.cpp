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
  vector<array<int, 3>> edges(m);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[i] = {a, b, c};
  }
  vector<int> par(n + 1, -1);
  vector<ll> dist(n + 1, 0);
  int node = -1;
  for (int i = 0; i < n; ++i) {
    node = -1;
    for (const auto &[a, b, c] : edges) {
      if (dist[b] > dist[a] + c) {
        dist[b] = dist[a] + c;
        par[b] = a;
        node = a;
      }
    }
    if (node == -1)
      break;
  }
  if (node == -1) {
    cout << "NO" << '\n';
    return 0;
  }
  for (int i = 0; i < n; ++i)
    node = par[node];
  vector<int> cycle = {node};
  for (int tmp = par[node]; tmp != node; tmp = par[tmp]) {
    cycle.push_back(tmp);
  }
  cycle.push_back(node);
  reverse(all(cycle));
  cout << "YES" << '\n';
  for (int u : cycle)
    cout << u << ' ';
}
