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
  vector<vector<pair<int, int>>> adj(n + 1); // u -> {v, length}
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }
  vector<ll> lengths(n + 1, 0);
  vector<bool> vis(n + 1, false);
  struct Cmp {
    bool operator()(const pair<int, ll> &a, const pair<int, ll> &b) {
      return a.second > b.second;
    }
  };
  priority_queue<pair<int, ll>, vector<pair<int, ll>>, Cmp> pq;
  pq.push({1, 0});
  while (!pq.empty()) {
    auto [u, l] = pq.top();
    pq.pop();
    if (vis[u])
      continue;
    vis[u] = true;
    lengths[u] = l;
    for (auto [v, dl] : adj[u]) {
      if (!vis[v])
        pq.push({v, l + dl});
    }
  }
  for (int i = 1; i <= n; ++i)
    cout << lengths[i] << ' ';
}
