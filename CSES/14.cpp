#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MXN = 1e5;
const int MOD = 1e9 + 7;

void solve(string n) {
  sort(n.begin(), n.end());
  vector<string> ans;
  do {
    ans.emplace_back(n);
  } while (next_permutation(n.begin(), n.end()));
  cout << ans.size() << '\n';
  for (const auto& s : ans) {
    cout << s << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string n;
  cin >> n;
  solve(n);
}
