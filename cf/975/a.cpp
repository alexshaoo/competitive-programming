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

const int MXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, ans = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> arr(n);
    vector<pair<int, int>> dp(n, {0, 0});
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    if (n == 1) {
      cout << 1+arr[0] << '\n';
    }
    for (int i = 0; i < n; ++i) {
      int f = 1, s = arr[i];
      if (i >= 3) {
        if (dp[i-3].first + dp[i-3].second > dp[i-2].first + dp[i-2].second) {
          f += dp[i-3].first;
          s = max(s, dp[i-3].second);
        } else {
          f += dp[i-2].first;
          s = max(s, dp[i-2].second);
        }
      } else if (i >= 2) {
        f += dp[i-2].first;
        s = max(s, dp[i-2].second);
      } else {
        s = arr[i];
      }
      dp[i] = {f, s};
    }
    // for (const auto& d : dp) {
      // cout << d.first << ' ' << d.second << '\n';
    // }
    cout << max(dp[n-1].first + dp[n-1].second, dp[n-1].first + dp[n-1].second) << '\n';
  }
}
