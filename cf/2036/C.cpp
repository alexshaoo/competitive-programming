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

bool eq(string& s, int i) {
  return s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0';
}

void solve() {
  string s;
  cin >> s;
  int n = sz(s);
  if (n < 4) {
    int q;
    cin >> q;
    while (q--) {
      int i, v;
      cin >> i >> v;
      cout << "NO\n";
    }
    return;
  }
  int count = 0;
  vector<bool> found(n - 3);
  for (int i = 0; i < n - 3; ++i) {
    if (eq(s, i)) {
      found[i] = true;
      ++count;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int i;
    char v;
    cin >> i >> v;
    --i;
    if (s[i] != v) {
      s[i] = v;
      for (int start = max(0, i - 3); start <= min(n - 4, i); ++start) {
        if (found[start] && !eq(s, start)) {
          found[start] = false;
          --count;
        } else if (!found[start] && eq(s, start)) {
          found[start] = true;
          ++count;
        }
      }
    }
    // cout << count << ' ' << s << '\n';
    cout << (count > 0 ? "YES" : "NO") << '\n';
  }
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
