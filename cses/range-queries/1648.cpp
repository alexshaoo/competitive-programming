
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

struct BIT {
  int n;
  vector<ll> arr;
  vector<ll> tree;
  BIT(const vector<ll> &arr) {
    n = sz(arr);
    tree.assign(n + 1, 0);
    this->arr.assign(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      this->arr[i + 1] = arr[i];
      tree[i + 1] = arr[i];
    }
    for (int i = 1; i <= n; ++i) {
      int par = i + (i & -i);
      if (par <= n)
        tree[par] += tree[i];
    }
  }
  ll query(int a) {
    ll sm = 0;
    while (a > 0) {
      int step = (a & -a);
      sm += tree[a];
      a -= step;
    }
    return sm;
  }
  ll query(int a, int b) { return query(b) - query(a - 1); }
  void update(int i, int val) {
    int d = val - arr[i];
    arr[i] = val;
    while (i <= n) {
      tree[i] += d;
      i += (i & -i);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  vector<ll> arr(n);
  for (ll &x : arr)
    cin >> x;
  BIT bit(arr);
  while (q--) {
    int x, a, b;
    cin >> x >> a >> b;
    if (x == 1) {
      // update
      bit.update(a, b);
    } else {
      // sum [a, b]
      cout << bit.query(a, b) << '\n';
    }
  }
}
