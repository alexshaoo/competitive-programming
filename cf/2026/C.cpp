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

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  string go;
  cin >> go;
  set<int> ones;
  ll ans = 0;
  while (n--) {
    if (go[n] == '0') {
      if (!ones.empty()) {
        ones.erase(prev(ones.end()));
      }
      ans += n + 1;
    } else {
      ones.insert(n + 1);
    }
  }
  // for (auto it = ones.begin(); it != ones.end(); ++it) {
  // cout << *it << ' ';
  // }
  // cout << '\n';
  auto it = ones.begin();
  for (int i = 0; i < (ones.size() + 1) / 2; ++i) {
    // cout << *it << ' ';
    ans += *it;
    ++it;
  }
  // cout << '\n';
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
