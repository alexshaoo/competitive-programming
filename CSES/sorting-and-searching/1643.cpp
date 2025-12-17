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
  ll arr[n];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  ll ans = arr[0], val = arr[0];
  for (int i = 1; i < n; ++i) {
    val = max(arr[i], arr[i] + val);
    ans = max(ans, val);
  }
  cout << ans << '\n';
}
