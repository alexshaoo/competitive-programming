#include <bits/stdc++.h>
using namespace std;

template <typename T, size_t SIZE>
void print(const T (&array)[SIZE]) {
  for (size_t i = 0; i < SIZE; i++) cout << array[i] << " ";
  cout << '\n';
}

template <class ForwardIter>
void print(ForwardIter begin, ForwardIter end) {
  for (; begin != end; ++begin) cout << *begin << " ";
  cout << '\n';
}

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 3e5 + 5;
const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n), ps(n + 1), psps(n + 2);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ps[i + 1] = ps[i] + a[i];
  }
  for (int i = 0; i <= n; ++i) {
    psps[i + 1] = psps[i] + ps[i];
  }
  vector<ll> bs(n), bsps(n + 1);  // sum of each 'block'
  for (int i = 0; i < n; ++i) {
    bs[i] = psps[n + 1] - psps[i + 1] - (n - i) * ps[i];
    bsps[i + 1] = bsps[i] + bs[i];
  }
  // print(all(psps));
  // print(all(bs));
  // auto sum = [&](int ind) -> ll {
  // int block = 1;
  // int size = n;
  // while (ind > size) {
  // ind -= size--;
  // ++block;
  // }
  // int mult = ind;
  // ll sum = 0;
  // for (int i = 0; i < ind; ++i) {
  // sum += a[i + block] * mult--;
  // }
  // return blockps[block - 1] + sum;
  // };
  auto sum = [&](ll X) -> ll {
    ll s = 0;
    ll e = n;
    while (s + 1 < e) {
      ll m = (s + e) / 2;
      ll lcnt = ll(m) * ll(n + n - (m - 1)) / 2;
      // cout << n + n - (m - 1) << ' ';
      if (X >= lcnt) {
        s = m;
      } else {
        e = m;
      }
    }
    cout << s << ' ';
    ll lcnt = ll(s) * ll(n + n - (s - 1)) / 2;
    ll nleft = X - lcnt;
    return bsps[s] + psps[s + 1 + nleft] - psps[s + 1] - nleft * ps[s];
  };
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    // cout << sr << ' ' << sl << '\n';
    cout << sum(r) - sum(l - 1) << '\n';
  }
}
