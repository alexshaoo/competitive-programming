#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

const int MAXN = 1e5 + 5;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> starts(n), ends(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    starts[i] = a;
    ends[i] = b;
  }
  sort(all(starts));
  sort(all(ends));
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int entered = i + 1;
    int left = lower_bound(all(ends), starts[i]) - ends.begin();
    ans = max(ans, entered - left);
  }
  cout << ans << '\n';
}