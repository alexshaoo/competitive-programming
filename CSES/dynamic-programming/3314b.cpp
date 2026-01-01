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
  vector<pair<int, int>> h(n); // {height, index}
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    h[i] = {x, i};
  }
  sort(h.rbegin(), h.rend());
  map<int, int> mp; // visited mountains, index -> max amount visitable
  mp[0] = 0;
  mp[n + 1] = 0;
  vector<pair<int, int>> updates; // index, max amount
  int prevHeight = 0;
  int ans = 0;
  for (auto [currHeight, currIndex] : h) {
    if (currHeight != prevHeight) {
      for (auto [i, v] : updates) {
        mp[i] = v;
      }
      updates.clear();
      prevHeight = currHeight;
    }
    auto it = mp.upper_bound(currIndex);
    auto nxt = it;
    --it;
    auto prev = it;
    int mx = max(nxt->second, prev->second) + 1;
    updates.push_back({currIndex, mx});
    ans = max(ans, mx);
  }
  cout << ans << '\n';
}
