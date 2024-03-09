#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MXN = 1e6;

void solve(ll n) {
  if (n == 1)
    cout << 1 << '\n';
  else if (n == 2 || n == 3)
    cout << "NO SOLUTION" << '\n';
  else {
    for (int i = 2; i <= n; i += 2) {
      cout << i << ' ';
    }
    for (int i = 1; i <= n; i += 2) {
      cout << i << ' ';
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  solve(n);
}