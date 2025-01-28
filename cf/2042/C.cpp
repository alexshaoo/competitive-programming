#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

const int MAXK = 1e9 + 5;
const int MOD = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> greedy;
  int dif = 0;
  for (int i = n - 1; i > 0; --i) {
    dif += (s[i] == '1') ? 1 : -1;
    if (dif > 0) greedy.push_back(dif);
  }
  sort(all(greedy), greater<int>());
  int score = 0;
  for (int i = 0; i < sz(greedy); ++i) {
    score += greedy[i];
    if (score >= k) {
      cout << i + 2 << '\n';
      return;
    }
  }
  cout << -1 << '\n';
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
