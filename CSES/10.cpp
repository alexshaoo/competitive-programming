#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MXN = 1e5;
const int MOD = 1e9 + 7;

void solve(ll a, ll b) {
  ll diff = abs(a - b);
  if (diff > min(a, b)) {
    cout << "NO" << '\n';
    return;
  }
  ll tot = a + b - 3 * diff;
  if (tot % 6 == 0) {
    cout << "YES" << '\n';
    return;
  }
  cout << "NO" << '\n';
  return;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    solve(a, b);
  }
}
