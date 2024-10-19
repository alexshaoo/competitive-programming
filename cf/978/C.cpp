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

void solve() {
  int n;
  cin >> n;
  array<string, 2> s;
  cin >> s[0] >> s[1];
  auto f = [&](char a, char b, char c) -> bool {
    return (a == 'A') + (b == 'A') + (c == 'A') >= 2;
  };
  vector<array<int, 2>> dp(n + 1);
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 3 == 0) {
      dp[i + 3][0] =
          max(dp[i + 3][0], dp[i][0] + f(s[0][i], s[0][i + 1], s[0][i + 2]) +
                                f(s[1][i], s[1][i + 1], s[1][i + 2]));
      dp[i + 1][0] =
          max(dp[i + 1][0], dp[i][0] + f(s[0][i], s[0][i + 1], s[1][i]));
      dp[i + 1][1] =
          max(dp[i + 1][1], dp[i][1] + f(s[0][i], s[1][i], s[1][i + 1]));
    } else if (i % 3 == 1) {
      if (i + 3 <= n) {
        dp[i + 3][0] = max(dp[i + 3][0],
                           dp[i][0] + f(s[0][i + 1], s[0][i + 2], s[0][i + 3]) +
                               f(s[1][i], s[1][i + 1], s[1][i + 2]));
        dp[i + 3][1] =
            max(dp[i + 3][1], dp[i][1] + f(s[0][i], s[0][i + 1], s[0][i + 2]) +
                                  f(s[1][i + 1], s[1][i + 2], s[1][i + 3]));
      }
      dp[i + 2][0] =
          max(dp[i + 2][0], dp[i][0] + f(s[0][i + 1], s[1][i], s[1][i + 1]));
      dp[i + 2][0] =
          max(dp[i + 2][0], dp[i][1] + f(s[0][i], s[0][i + 1], s[1][i + 1]));
    }
  }
  cout << dp[n][0] << '\n';
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
