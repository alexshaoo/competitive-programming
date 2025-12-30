#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

using State = pair<ll, int>;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> adj(n + 1); // u -> {length, v}
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
  }
  priority_queue<State, vector<State>, greater<State>> pq;
  pq.push({0, 1});
  vector<int> cnts(n + 1, 0);
  vector<ll> costs;
  while (!pq.empty()) {
    auto [c, u] = pq.top();
    pq.pop();
    if (u == n) {
      if (cnts[u] == k)
        break;
      costs.push_back(c);
    } else if (cnts[u] == k)
      continue;
    cnts[u]++;
    for (auto [dc, v] : adj[u]) {
      pq.push({c + dc, v});
    }
  }
  for (ll c : costs)
    cout << c << ' ';
}
