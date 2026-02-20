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
  vector<int> v;
  while (n--) {
    int x;
    cin >> x;
    if (v.empty() || x >= v.back()) {
      v.push_back(x);
    } else {
      auto it = upper_bound(all(v), x);
      *it = x;
    }
  }
  cout << v.size() << '\n';
}
