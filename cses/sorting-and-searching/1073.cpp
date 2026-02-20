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
  map<int, int> freq;
  while (n--) {
    int x;
    cin >> x;
    auto it = freq.upper_bound(x);
    if (it == freq.end()) {
      freq[x]++;
    } else {
      int currIndex = (*it).first;
      if (freq[currIndex] > 0) {
        freq[currIndex]--;
        if (freq[currIndex] == 0)
          freq.erase(currIndex);
      }
      freq[x]++;
    }
  }
  int cnt = 0;
  for (auto &[_, v] : freq) {
    cnt += v;
  }
  cout << cnt << '\n';
}
