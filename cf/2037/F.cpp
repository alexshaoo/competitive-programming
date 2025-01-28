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
const int MAXH = 1e9 + 5;
const int MOD = 1e9 + 7;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> health(n), pos(n);
  for (int i = 0; i < n; ++i) {
    cin >> health[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> pos[i];
  }
  int l = 0, r = MAXH;
  auto f = [&](int numAttacks) -> int {
    vector<int> s, e;
    for (int i = 0; i < n; ++i) {
      if ((__int64)m * numAttacks < health[i]) continue;
      int dist = m - (health[i] / numAttacks + (health[i] % numAttacks != 0));
      s.push_back(pos[i] - dist);
      e.push_back(pos[i] + dist + 1);
    }
    sort(all(s));
    sort(all(e));
    int sp = 0, ep = 0;
    int mx = 0, enemiesDead = 0;
    while (sp < sz(s)) {
      while (e[ep] <= s[sp]) {
        --enemiesDead;
        ++ep;
      }
      ++enemiesDead;
      ++sp;
      mx = max(mx, enemiesDead);
    }
    return mx;
  };
  while (l < r) {
    int m = l + (r - l) / 2;
    int enemiesKilled = f(m);
    if (enemiesKilled >= k) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << ((l == MAXH) ? -1 : l) << '\n';
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
