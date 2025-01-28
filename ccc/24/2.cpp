#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(string s, int n) {
  int fre[26] = {0};
  for (auto c : s) {
    fre[c - 'a']++;
  }
  bool light = (fre[s[0] - 'a'] == 1);
  for (int i = 1; i < s.length(); ++i) {
    light = !light;
    if (light != (fre[s[i] - 'a'] == 1)) {
      cout << 'F' << '\n';
      return;
    }
  }
  cout << 'T' << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, n;
  cin >> t >> n;
  for (int i = 0; i < t; ++i) {
    string s;
    cin >> s;
    solve(s, n);
  }
}
