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
  map<int, int> lastPos;
  int mx = 0, l = 0;
  for (int r = 1; r <= n; ++r) {
    int x;
    cin >> x;
    l = max(l, lastPos[x]);
    mx = max(mx, r - l);
    lastPos[x] = r;
  }
  cout << mx << '\n';
}
