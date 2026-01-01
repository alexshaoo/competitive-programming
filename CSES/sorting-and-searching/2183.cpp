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
  vector<int> coins(n);
  for (int &coin : coins)
    cin >> coin;
  sort(all(coins));
  ll mx = 0;
  for (int coin : coins) {
    if (coin > mx + 1) {
      break;
    }
    mx += coin;
  }
  cout << mx + 1 << '\n';
}
