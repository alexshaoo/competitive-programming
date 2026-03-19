#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll sm = 0;
  int l = 0;
  int n;
  cin >> n;
  map<int, int> last;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    l = max(l, last[x]);
    sm += (i - l);
    last[x] = i;
  }
  cout << sm << '\n';
}
