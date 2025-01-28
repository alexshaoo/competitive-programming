#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MXN = 1e5;
const int MOD = 1e9 + 7;

void solve(ll a, ll b) {
  cout << ((a + b) % 3 == 0 && 2 * a >= b && 2 * b >= a ? "YES" : "NO") << '\n';
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
