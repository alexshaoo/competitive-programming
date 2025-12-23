#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> h(n);
  for (int &x : h)
    cin >> x;
  vector<int> L(n), R(n);
  stack<int> s;
  for (int i = 0; i < n; ++i) {
    while (!s.empty() && h[s.top()] < h[i])
      s.pop();
    if (s.empty())
      L[i] = -1;
    else
      L[i] = s.top();
    s.push(i);
  }
  s = stack<int>();
  for (int i = n - 1; i >= 0; --i) {
    while (!s.empty() && h[s.top()] < h[i])
      s.pop();
    if (s.empty())
      R[i] = n;
    else
      R[i] = s.top();
    s.push(i);
  }
  vector<int> dp(n, 1);
  vector<int> segtree(2 * n, 0);
  auto update = [&](int i, int val) {
    i += n;
    segtree[i] = val;
    for (; i > 1; i >>= 1) {
      int sibling = i ^ 1;
      segtree[i >> 1] = max(segtree[i], segtree[sibling]);
    }
  };
  auto query = [&](int l, int r) {
    int res = 0;
    l += n;
    r += n;
    for (; l <= r; l >>= 1, r >>= 1) {
      if (l & 1)
        res = max(res, segtree[l++]);
      if (!(r & 1))
        res = max(res, segtree[r--]);
    }
    return res;
  };
  vector<int> p(n);
  iota(all(p), 0);
  sort(all(p), [&](const int &a, const int &b) { return h[a] < h[b]; });
  int i = 0;
  while (i < n) {
    int currHeight = h[p[i]];
    vector<int> toAdd;
    while (i < n && h[p[i]] == currHeight) {
      int j = p[i];
      dp[j] = 1 + query(L[j] + 1, R[j] - 1);
      toAdd.push_back(j);
      ++i;
    }
    for (int j : toAdd) {
      update(j, dp[j]);
    }
  }
  cout << *max_element(all(dp));
}
