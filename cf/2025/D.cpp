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

const int MAXM = 5e3 + 5;
const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> dp(MAXM, vector<int>(MAXM));
  int c = 0;
  for (int i = 0; i < n; ++i) {
    int r;
    cin >> r;
    if (r == 0) {
      ++c;
      dp[c][0] = dp[c - 1][0];
      dp[0][c] = dp[0][c - 1];
      for (int i = 1; i < c; ++i) {
        dp[i][c - i] = max(dp[i - 1][c - i], dp[i][c - i - 1]);
      }
    } else if (r > 0 && c > 0) {
      dp[c][0] += (c >= r);
      for (int i = 1; i < c; ++i) {
        dp[i][c - i] += (i >= r);
      }
    } else if (r < 0 && c > 0) {
      dp[0][c] += (c >= -r);
      for (int i = 1; i < c; ++i) {
        dp[i][c - i] += (c - i >= -r);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= m; ++i) {
    ans = max(ans, dp[i][m - i]);
  }
  cout << ans << '\n';
}
