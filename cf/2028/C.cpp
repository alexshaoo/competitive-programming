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

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

void solve() {
  ll n, m, v;
  cin >> n >> m >> v;
  vector<ll> a(n), ps(n + 1);
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
    ps[i + 1] = ps[i] + a[i];
  }
  ll l = 0;
  vector<ll> leftPieces;
  for (ll i = 0; i <= n; ++i) {
    if (ps[i] - ps[l] >= v) {
      l = i;
      leftPieces.push_back(l - 1);
    }
  }
  ll r = n;
  vector<ll> rightPieces;
  for (ll i = n; i >= 0; --i) {
    if (ps[r] - ps[i] >= v) {
      r = i;
      rightPieces.push_back(r);
    }
  }
  // print(all(ps));
  // print(all(leftPieces));
  // print(all(rightPieces));
  if (sz(leftPieces) < m || sz(rightPieces) < m) {
    cout << -1 << '\n';
    return;
  }
  ll ans = 0;
  for (ll lm = 0; lm <= m; ++lm) {
    ll rm = m - lm;
    if (lm < sz(leftPieces) && rm <= sz(rightPieces)) {
      ll tastiness = 0;
      if (lm != 0 && rm != 0) {
        tastiness = ps[rightPieces[rm - 1]] - ps[leftPieces[lm]];
      } else if (lm != 0) {
        tastiness = ps[n] - ps[leftPieces[lm]];
      } else if (rm != 0) {
        tastiness = ps[rightPieces[rm - 1]] - ps[0];
      }
      // cout << tastiness << ' ';
      ans = max(ans, tastiness);
    }
  }
  cout << ans << '\n';
  return;
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
