#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

constexpr int MAXN = 2e5 + 5;
ll x[MAXN] = {0};
ll segtree[2 * MAXN] = {0};

void build(int i, int l, int r) {
  if (l == r) {
    segtree[i] = x[l];
    return;
  }
  int m = (l + r) / 2;
  build(2 * i, l, m);
  build(2 * i + 1, m + 1, r);
  segtree[i] = segtree[2 * i] + segtree[2 * i + 1];
}

void update(int i, int l, int r, int k, ll u) {
  if (l == r) {
    segtree[i] = u;
    return;
  } else {
    int m = (l + r) / 2;
    if (k <= m) {
      update(2 * i, l, m, k, u);
    } else {
      update(2 * i + 1, m + 1, r, k, u);
    }
    segtree[i] = segtree[2 * i] + segtree[2 * i + 1];
  }
}

ll query(int i, int l, int r, int a, int b) {
  if (l > r)
    return 0;
  if (l == a && r == b)
    return segtree[i];
  int m = (l + r) / 2;
  if (m >= b)
    return query(2 * i, l, m, a, b);
  if (m < a)
    return query(2 * i + 1, m + 1, r, a, b);
  return query(2 * i, l, m, a, min(m, b)) +
         query(2 * i + 1, m + 1, r, max(m + 1, a), b);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i)
    cin >> x[i];
  build(1, 1, n);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int k;
      ll u;
      cin >> k >> u;
      update(1, 1, n, k, u);
    } else {
      int a, b;
      cin >> a >> b;
      cout << query(1, 1, n, a, b) << '\n';
    }
  }
  return 0;
}
