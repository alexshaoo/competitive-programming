#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MXN = 1e5;

void solve(ll n) {}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n, s = 0;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int nn;
    cin >> nn;
    s += nn;
  }
  cout << n * (n + 1) / 2 - s << '\n';
}