#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MXN = 1e6;

int solve(string s) {
  char cur = 'A';
  int mx = 1, c = 0;
  for (char ss : s) {
    if (ss == cur) {
      ++c;
      mx = max(mx, c);
    } else {
      c = 1;
      cur = ss;
    }
  }
  return mx;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  cout << solve(s) << '\n';
}