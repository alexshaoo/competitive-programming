#include <bits/stdc++.h>
using namespace std;

// TODO: Implement this.
// Return the lexicographically-smallest valid increasing order of all distinct
// symbols, or empty vector if impossible. Input pairs encode "x > y" (i.e., in
// the increasing sequence, y must appear before x).
vector<char> infer_order_from_gt_pairs(vector<pair<char, char>> &pairs) {
  unordered_map<int, vector<int>> adj(26);
  unordered_map<int, int> indegs;
  for (const auto &[u, v] : pairs) {
    adj[u - 'a'].push_back(v - 'a');
    indegs[u - 'a'] += 0;
    indegs[v - 'a']++;
  }
  queue<int> q;
  for (const auto &[u, indeg] : indegs) {
    cout << u << ' ' << indeg << '\n';
    if (indeg == 0) {
      q.push(u);
    }
  }
  vector<bool> vis(26);
  vector<char> ans;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (vis[u])
      return {};
    ans.push_back(u + 'a');
    vis[u] = true;
    for (const auto &v : adj[u]) {
      indegs[v]--;
      if (indegs[v] == 0)
        q.push(v);
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<char, char>> pairs(n);
  for (int i = 0; i < n; ++i) {
    char x, y;
    cin >> x >> y;
    pairs.emplace_back(x, y);
  }
  auto ans = infer_order_from_gt_pairs(pairs);
  for (char c : ans) {
    cout << c << ' ';
  }
  cout << '\n';
  return 0;
}
