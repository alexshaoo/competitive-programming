#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

struct Project {
  int a, b;
  ll reward;
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<Project> projects(n);
  for (auto &[a, b, reward] : projects) {
    cin >> a >> b >> reward;
  }

  sort(all(projects),
       [&](const Project &a, const Project &b) { return a.b < b.b; });

  vector<int> ends(n);
  for (int i = 0; i < n; ++i)
    ends[i] = projects[i].b;
  vector<ll> dp(n + 1);
  for (int i = 0; i < n; ++i) {
    auto it = lower_bound(all(ends), projects[i].a);
    int idx = distance(ends.begin(), it);
    dp[i + 1] = max(dp[i], projects[i].reward + dp[idx]);
  }

  cout << dp[n] << '\n';
}
