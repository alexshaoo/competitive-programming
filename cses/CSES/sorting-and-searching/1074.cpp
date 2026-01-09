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
  vector<int> p(n);
  for (int &num : p)
    cin >> num;
  sort(all(p));
  auto f = [&](int x) {
    ll d = 0;
    for (int num : p)
      d += abs(num - x);
    return d;
  };
  int l = 1, r = 1e9;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (f(m) > f(m + 1))
      l = m + 1;
    else
      r = m - 1;
  }
  cout << f(l) << '\n';
}
