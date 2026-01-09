#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  set<array<int, 2>> prices;  // price, ind
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int price;
    cin >> price;
    prices.insert({price, i});
  }
  for (int i = 0; i < m; ++i) {
    int mx;
    cin >> mx;
    auto it = prices.upper_bound({mx + 1, 0});
    if (it == prices.begin()) {
      cout << -1 << '\n';
    } else {
      --it;
      cout << (*it)[0] << '\n';
      prices.erase(prices.find(*it));
    }
  }
}
