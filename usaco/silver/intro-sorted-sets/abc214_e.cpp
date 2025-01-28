#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

const int MAXN = 1e5 + 5;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<pair<int, int>> ranges(N);
    for (int i = 0; i < N; ++i) {
      cin >> ranges[i].first >> ranges[i].second;
    }
    sort(all(ranges));
    set<int> r;
    int pos = 1, range = 0;
    // for (auto [l, r] : ranges) {
    // cout << l << ' ' << r << '\n';
    // }
    // while i still have balls to place
    // set pos to next location to place balls (upper_bound of current pos)
    // process all ranges at that pos
    // get r[0]
    // if none, failed. else, pop one
    bool valid = true;
    while (pos <= 1e9 && range < N) {
      auto it = lower_bound(ranges.begin() + range, ranges.end(),
                            make_pair(pos, INT_MIN));
      if (it == ranges.end()) {
        valid = false;
        break;
      }
      pos = it->first;
      while (range < N && ranges[range].first == pos) {
        r.insert(ranges[range].second);
        range++;
      }
      cout << r.size() << '\n';
      if (r.empty()) {
        valid = false;
        cout << "we";
        break;
      }
      int l = *(r.begin());
      cout << l << ' ' << pos << '\n';
      if (l < pos) {
        valid = false;
        cout << "Wes";
        break;
      }
      r.erase(r.begin());
      ++pos;
      cout << (pos <= 1e9) << ' ' << (range < N) << '\n';
    }
    if (valid || range == N)
      cout << "Yes";
    else
      cout << "No";
    cout << '\n';
  }
}
