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
const int MOD = 1e9 + 7;

void solve() {
  int n, m, L;
  cin >> n >> m >> L;
  vector<pii> hurdles(n);
  for (int i = 0; i < n; ++i) {
    cin >> hurdles[i].first >> hurdles[i].second;
  }
  vector<pii> powerups(m);
  for (int i = 0; i < m; ++i) {
    cin >> powerups[i].first >> powerups[i].second;
  }
  priority_queue<int> canCollect;
  ll jump = 1;
  int ans = 0;
  int powerupIndex = 0;
  for (int i = 0; i < n; ++i) {
    auto [l, r] = hurdles[i];
    while (powerupIndex < m && powerups[powerupIndex].first < l) {
      canCollect.push(powerups[powerupIndex++].second);
    }
    while (jump < r - l + 2 && !canCollect.empty()) {
      jump += canCollect.top();
      canCollect.pop();
      ++ans;
    }
    if (jump < r - l + 2) {
      cout << -1 << '\n';
      return;
    }
  }
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
