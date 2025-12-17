#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MXN = 1e5;
const int MOD = 1e9 + 7;

void solve(string s) {
  int c[26] = {};
  int c1 = 0;
  for (char d : s) {
    ++c[d - 'A'];
  }
  for (int i = 0; i < 26; ++i) {
    c1 += c[i] & 1;
  }
  if (c1 > 1) {
    cout << "NO SOLUTION";
    return;
  }
  string ans;
  for (int i = 0; i < 26; ++i) {
    if (c[i] & 1 ^ 1) {
      for (int j = 0; j < c[i] / 2; ++j) {
        ans += (char)('A' + i);
      }
    }
  }
  cout << ans;
  for (int i = 0; i < 26; ++i) {
    if (c[i] & 1) {
      for (int j = 0; j < c[i]; ++j) {
        cout << (char)('A' + i);
      }
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string n;
  cin >> n;
  solve(n);
}