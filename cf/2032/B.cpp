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
  int n, k;
  cin >> n >> k;
  if (n == 1) {
    cout << "1" << '\n';
    cout << (k == 1) ? "1" : "-1";
    cout << '\n';
    return;
  }
  if (k == 1 || k == n) {
    cout << "-1\n";
    return;
  }
  cout << "3" << '\n';
  if (k % 2 == 0) {
    cout << "1 " << k << ' ' << k + 1 << '\n';

  } else {
    cout << "1 " << k - 1 << ' ' << k + 2 << '\n';
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
