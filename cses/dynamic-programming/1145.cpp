#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  // dp[i] = smallest value of the last element in subsequence we've seen so far
  vector<int> dp;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    auto it = lower_bound(all(dp), x);
    if (it == dp.end()) {
      dp.push_back(x);
    } else {
      *it = x;
    }
  }
  cout << sz(dp) << '\n';
}
