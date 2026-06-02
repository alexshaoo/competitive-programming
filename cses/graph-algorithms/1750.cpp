#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;

  // dp[i][j] is planet you end up on from planet i with j jumps
  vector<vector<int>> dp(n + 1, vector<int>(31, 0));
  for (int i = 1; i <= n; ++i) {
    cin >> dp[i][0];
  }
  for (int j = 1; j <= 30; ++j) {
    for (int i = 1; i <= n; ++i) {
      int nxt = dp[i][j - 1];
      dp[i][j] = dp[nxt][j - 1];
    }
  }

  while (q--) {
    int x, k;
    cin >> x >> k;
    for (int b = 0; b <= 30; ++b) {
      if (k & (1 << b))
        x = dp[x][b];
    }
    cout << x << '\n';
  }
}
