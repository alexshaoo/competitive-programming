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

#define ll long long
#define all(x) (x).begin(), (x).end()

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

vector<ll> peaks;

int solve() {
  ll a, b, m;
  cin >> a >> b >> m;
  int ans = 0;
  ll l = *lower_bound(all(peaks), a);
  while (l <= b) {
    if (l % m == 0) {
      ++ans;
    }
    l = *upper_bound(all(peaks), l);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i <= 9; ++i) {        // length of uphill
    for (int j = 1; j <= 9 - i; ++j) {  // starting number
      ll num = 0;
      for (int k = j; k <= j + i; ++k) {
        num = 10 * num + k;
      }

      for (int k = j + i - 1; k >= j; --k) {
        num = 10 * num + k;
      }
      peaks.push_back(num);
    }
  }
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": " << solve() << '\n';
  }
}
