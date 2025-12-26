#include <bits/stdc++.h>

using namespace std;

void f(int u, int sm, vector<int> &S1, vector<int> &S2, vector<int> &tree,
       unordered_map<int, vector<int>> &adj) {
  S1[u] = sm;
  int subtreeSum = tree[u];
  for (int v : adj[u]) {
    f(v, sm + tree[v], S1, S2, tree, adj);
    subtreeSum += S2[v];
  }
  S2[u] = subtreeSum;
}

int main() {
  int n;
  cin >> n;
  vector<int> tree(n + 1);
  unordered_map<int, vector<int>> adj;
  for (int i = 1; i <= n; ++i) {
    cin >> tree[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  vector<int> S1(n + 1), S2(n + 1);
  f(1, tree[1], S1, S2, tree, adj);
  for (int i = 1; i <= n; ++i) {
    cout << S1[i] << ' ' << S2[i] << '\n';
  }
  int sm = 0;
  for (int i = 1; i <= n; ++i) {
    int diff = abs(S1[i] - S2[i]);
    cout << diff << '\n';
    sm += diff;
  }
  cout << sm << '\n';
}
