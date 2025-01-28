#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

const int MAXN = 1e5 + 5;

int main() {
  setIO("snowboots");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, b;
  cin >> n >> b;
  if (n <= 1) {
    int tmp;
    cin >> tmp;
    // handle this case separately if need be
  }
  vector<pair<int, int>> depths(n + 2);
  for (int i = 1; i <= n; ++i) {
    cin >> depths[i].first;
    depths[i].second = i;
  }
  sort(all(depths));
  reverse(all(depths));
  vector<array<int, 3>> boots(b);
  for (int i = 0; i < b; ++i) {
    int s, d;  // depth, stride
    cin >> s >> d;
    boots[i] = {s, d, i};
  }
  sort(all(boots));
  reverse(all(boots));
  unordered_map<int, pair<int, int>> ll;
  for (int i = 1; i <= n; ++i) {
    ll[i] = {i - 1, i + 1};
  }
  int maxDist = 1;
  vector<int> ans(b);
  int di = 0;
  for (const auto& [depth, stride, i] : boots) {
    while (depths[di].first > depth) {
      auto [l, r] = ll[depths[di].second];
      ll[l].second = r;
      ll[r].first = l;
      maxDist = max(maxDist, r - l);
      ++di;
    }
    if (stride >= maxDist) {
      ans[i] = 1;
    } else {
      ans[i] = 0;
    }
  }
  for (int a : ans) cout << a << '\n';
}
