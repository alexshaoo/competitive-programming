#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<array<int, 3>> segments(n);  // l, r, i
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    segments[i] = {l, r, i};
  }
  vector<int> ans(n);
  //
  sort(all(segments), [](const array<int, 3>& a, const array<int, 3>& b) {
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] > b[1];
  });
  set<int> l;
  for (const auto& segment : segments) {
    if (!l.empty()) {
      auto sl = l.upper_bound(segment[0]);
      if (sl != l.begin()) {
        --sl;
        ans[segment[2]] += max(0, segment[0] - *sl);
      }
    }
    l.insert(segment[0]);
  }
  sort(all(segments), [](const array<int, 3>& a, const array<int, 3>& b) {
    if (a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
  });
  set<int> r;
  for (const auto& segment : segments) {
    if (!r.empty()) {
      auto sr = r.lower_bound(segment[1]);
      ans[segment[2]] += max(0, *sr - segment[1]);
    }
    r.insert(segment[1]);
  }
  for (int i = 0; i < n - 1; ++i) {
    if (segments[i][0] == segments[i + 1][0] &&
        segments[i][1] == segments[i + 1][1]) {
      ans[segments[i][2]] = 0;
      ans[segments[i + 1][2]] = 0;
    }
  }
  for (int val : ans) {
    cout << val << '\n';
  }
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
