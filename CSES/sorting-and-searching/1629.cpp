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
  vector<pair<int, int>> movies(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    movies[i] = {a, b};
  }
  sort(all(movies),
       [](const auto& a, const auto& b) { return a.second < b.second; });
  int end = 1;
  int ind = 0;
  int ans = 0;
  while (ind < n) {
    if (movies[ind].first >= end) {
      ++ans;
      end = movies[ind].second;
    }
    ++ind;
  }
  cout << ans << '\n';
}
