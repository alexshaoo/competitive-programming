#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

const int MAXN = 1e6 + 5;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> dp(n + 1, MAXN);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int tmp = i;
    while (tmp > 0) {
      int d = tmp % 10;
      if (i - d >= 0)
        dp[i] = min(dp[i], 1 + dp[i - d]);
      tmp /= 10;
    }
  }
  cout << dp[n] << '\n';
}
