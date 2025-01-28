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
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  int x = 0, y = 0;
  for (int i = 0; i < MAXN; ++i) {
    for (auto ch : s) {
      if (ch == 'N') ++y;
      if (ch == 'S') --y;
      if (ch == 'E') ++x;
      if (ch == 'W') --x;
      if (a == x && b == y) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
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
