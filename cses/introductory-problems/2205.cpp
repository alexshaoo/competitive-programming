#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

const int MXN = 1e5;
const int MOD = 1e9 + 7;

int c = 0;
vector<pii> ans;

void solve(ll n, ll from, ll to) {
  if (n == 1) {
    ++c;
    ans.emplace_back(make_pair(from, to));
    return;
  }
  int other = 6 - from - to;
  solve(n - 1, from, other);
  ++c;
  ans.emplace_back(make_pair(from, to));
  solve(n - 1, other, to);
  return;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  solve(n, 1, 3);
  cout << c << '\n';
  for (pii p : ans) {
    cout << p.first << ' ' << p.second << '\n';
  }
}
