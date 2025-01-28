#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MXT = 1e5, MXY = 1e9, MXX = 1e9;
void solve(ll x, ll y) {
  ll val;
  if (x > y) {
    if (x % 2 == 0) {
      val = x * x;
      while (--y) {
        --val;
      }
    } else {
      val = (x - 1) * (x - 1) + 1;
      while (--y) {
        ++val;
      }
    }
  } else {
    if (y % 2 == 0) {
      val = (y - 1) * (y - 1) + 1;
      while (--x) {
        ++val;
      }
    } else {
      val = y * y;
      while (--x) {
        --val;
      }
    }
  }
  cout << val << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  while (n--) {
    ll x, y;
    cin >> x >> y;
    solve(x, y);
  }
}