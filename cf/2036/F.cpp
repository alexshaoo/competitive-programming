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
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1e5 + 5;

ll f(ll a) {
  ll res[] = {a, 1, a + 1, 0};
  return res[a % 4];
}

ll xorRange(ll a, ll b) { return f(b) ^ f(a - 1); }

void solve() {
  ll l, r, i, k;
  cin >> l >> r >> i >> k;
  ll tot = xorRange(l, r);
  ll MOD = 1LL << i;
  ll exc =
      k + MOD +
      MOD * ((l - 1) / MOD);  // wrong but the entire idea is too slow anyway

  ll addBack = 0;
  for (ll x = exc; x <= r; x += MOD) {
    cout << x << ' ';
    addBack ^= x;
  }

  ll ans = tot ^ addBack;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
