#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

#define INF (int)1e6 + 5

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  int coins[n];
  for (int i = 0; i < n; ++i) {
    cin >> coins[i];
  }
  int dp[x + 1];
  fill(dp, dp + x + 1, INF);  // use vector next time lol
  dp[0] = 0;
  for (int i = 1; i <= x; ++i) {
    for (int coin : coins) {
      if (i - coin >= 0 && dp[i - coin] != -1) {
        dp[i] = min(dp[i], dp[i - coin] + 1);
      }
    }
  }
  cout << (dp[x] == INF ? -1 : dp[x]) << '\n';
}
