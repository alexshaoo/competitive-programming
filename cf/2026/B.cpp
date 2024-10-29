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

#define ull unsigned long long
#define ll long long
#define all(x) (x).begin(), (x).end()

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<ull> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  vector<ull> pre = {1}, suf = {1};
  for (int i = 0; i < n / 2; ++i) {
    pre.push_back(max(pre[i], arr[2 * i + 1] - arr[2 * i]));
    suf.push_back(max(suf[i], arr[n - 2 * i - 1] - arr[n - 2 * i - 2]));
  }
  if (n % 2 == 0) {
    cout << pre[n / 2] << '\n';
  } else {
    ull ans = ULLONG_MAX;
    for (int i = 0; i <= n / 2; ++i) {
      ans = min(ans, max(pre[i], suf[n / 2 - i]));
    }
    cout << ans << '\n';
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
