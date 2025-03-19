#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  int cnt = 1;  // power of 2 that's bigger than n
  while ((1 << cnt) <= n) ++cnt;
  vector<vector<int>> st(n, vector<int>(cnt));
  for (int i = 0; i < n; ++i) {
    st[i][0] = x[i];
  }
  for (int range = 1; range < cnt; ++range) {
    for (int start = 0; start <= n - (1 << range); ++start) {
      st[start][range] =
          min(st[start][range - 1], st[start + (1 << (range - 1))][range - 1]);
    }
  }
  while (q--) {
    int a, b;
    cin >> a >> b;
    int p = 31 - __builtin_clz(b - a + 1);
    cout << min(st[a - 1][p], st[b - (1 << p)][p]) << '\n';
  }
}
