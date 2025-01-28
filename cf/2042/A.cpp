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

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(all(a), greater<int>());
  int sm = 0;
  for (int i = 0; i < n; ++i) {
    if (sm + a[i] == k) {
      cout << 0 << '\n';
      return;
    }
    if (sm + a[i] > k) {
      cout << k - sm << '\n';
      return;
    }
    sm += a[i];
  }
  cout << k - sm << '\n';
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
