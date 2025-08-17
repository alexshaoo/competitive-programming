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
  string s;
  cin >> s;

  vector<vector<int>> tc(26, vector<int>(n + 1, 0));
  for (char c = 'a'; c <= 'z'; ++c) {
    for (int i = 0; i < n; ++i) {
      tc[c - 'a'][i + 1] = tc[c - 'a'][i] + (s[i] == c);
    }
  }

  vector<vector<int>> ans(26, vector<int>(n + 1, 0));
  for (char c = 'a'; c <= 'z'; ++c) {
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        int len = j - i + 1;
        int bad = len - (tc[c - 'a'][j + 1] - tc[c - 'a'][i]);
        ans[c - 'a'][bad] = max(ans[c - 'a'][bad], len);
      }
    }
  }

  for (char c = 'a'; c <= 'z'; ++c) {
    for (int i = 1; i <= n; ++i) {
      ans[c - 'a'][i] = max(ans[c - 'a'][i], ans[c - 'a'][i - 1]);
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int m;
    char c;
    cin >> m >> c;
    cout << ans[c - 'a'][m] << '\n';
  }
}
