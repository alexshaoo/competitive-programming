#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

bool valid(int n, multiset<int, greater<int>> ms) {
  return *ms.begin() <= (n + 1) / 2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.length();
  map<char, int> mp;
  for (char c : s) {
    mp[c]++;
  }
  multiset<int, greater<int>> ms;
  for (auto it = mp.begin(); it != mp.end(); ++it) {
    ms.insert(it->second);
  }
  string ans = "";
  if (!valid(n, ms)) {
    cout << -1 << '\n';
  } else {
    for (int i = 0; i < n; ++i) {
      for (auto it = mp.begin(); it != mp.end(); ++it) {
        char c = it->first;
        int freq = it->second;
        if (i > 0 && c == ans[i - 1]) continue;
        ms.erase(ms.find(freq));
        ms.insert(freq - 1);
        if (valid(n - i - 1, ms)) {
          it->second--;
          if (it->second == 0) mp.erase(it);
          ans += c;
          break;
        }
        ms.erase(ms.find(freq - 1));
        ms.insert(freq);
      }
    }
  }
  cout << ans << '\n';
}
