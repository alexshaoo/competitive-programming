#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MXN = 1e6;

void solve(ll n) {
  while (n > 1) {
    cout << n << ' ';
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = 3 * n + 1;
    }
  }
  cout << n << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  solve(n);
}