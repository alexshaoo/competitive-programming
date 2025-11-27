#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> prices(n), pages(n);
  for (int i = 0; i < n; ++i)
    cin >> prices[i];
  for (int i = 0; i < n; ++i)
    cin >> pages[i];
  // dp[first i books][price at most x]
  vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int price = 0; price <= x; ++price) {
      dp[i][price] = dp[i - 1][price];
      int rem = price - prices[i - 1];
      if (rem >= 0)
        dp[i][price] = max(dp[i][price], dp[i - 1][rem] + pages[i - 1]);
    }
  }
  cout << dp[n][x] << '\n';
}
