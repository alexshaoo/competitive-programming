#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    // max wins for either side is n-1
    // also can't have a win >0 games and b win 0 games, and vice versa
    if (a + b > n || (a == 0) ^ (b == 0)) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
      vector<int> av, bv;
      for (int i = 1; i <= a; ++i) {
        av.push_back(i + b);
        bv.push_back(i);
      }
      for (int i = 1; i <= b; ++i) {
        av.push_back(i);
        bv.push_back(i + a);
      }
      for (int i = a + b + 1; i <= n; ++i) {
        av.push_back(i);
        bv.push_back(i);
      }
      for (auto num : av) cout << num << ' ';
      cout << '\n';
      for (auto num : bv) cout << num << ' ';
      cout << '\n';
    }
  }
  return 0;
}
