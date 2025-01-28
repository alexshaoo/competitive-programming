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
  int n;
  cin >> n;
  if (n < 5) {
    cout << -1 << '\n';
    return;
  }
  vector<int> evens = {4}, odds = {5};
  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 0 && i != 4) {
      evens.push_back(i);
    }
    if (i % 2 == 1 && i != 5) {
      odds.push_back(i);
    }
  }
  reverse(all(odds));
  odds.insert(odds.end(), all(evens));
  print(all(odds));
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
