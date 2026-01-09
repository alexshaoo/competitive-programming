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
  vector<int> coins(n);
  for (auto &coin : coins)
    cin >> coin;
  int sm = accumulate(all(coins), 0);
  vector<bool> can(sm + 1, false);
  can[0] = true;
  for (int coin : coins) {
    for (int s = sm - coin; s >= 0; --s) {
      if (can[s])
        can[s + coin] = true;
    }
  }
  vector<int> ans;
  for (int s = 1; s <= sm; ++s) {
    if (can[s])
      ans.push_back(s);
  }
  cout << ans.size() << '\n';
  for (int num : ans)
    cout << num << ' ';
}
