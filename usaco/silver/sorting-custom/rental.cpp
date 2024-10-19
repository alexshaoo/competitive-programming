#include <bits/stdc++.h>
using namespace std;

template <typename T, size_t SIZE>
void print(const T (&array)[SIZE]) {
  for (size_t i = 0; i < SIZE; i++) cout << array[i] << " ";
  cout << '\n';
}

template <class ForwardIter>
void print(ForwardIter begin, ForwardIter end) {
  for (; begin != end; ++begin) cout << *begin << " ";
  cout << '\n';
}

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

#define ll long long
#define all(x) (x).begin(), (x).end()

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int main() {
  setIO("rental");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n, m, _r;
  cin >> n >> m >> _r;
  vector<ll> prod(n);
  for (ll i = 0; i < n; ++i) {
    cin >> prod[i];
  }
  sort(all(prod), greater<>());
  vector<pair<ll, ll>> sell(m);
  for (ll i = 0; i < m; ++i) {
    cin >> sell[i].second >> sell[i].first;  // sort by cents/gallon
  }
  sort(all(sell), greater<>());
  vector<ll> rent(_r);
  for (ll i = 0; i < _r; ++i) {
    cin >> rent[i];
  }
  sort(all(rent), greater<>());
  ll l = 0;
  ll r = min(n, _r);
  auto solve = [&](ll numRent) {
    ll profit = 0;
    for (ll i = 0; i < numRent; ++i) {
      profit += rent[i];
    }
    ll gallons = 0;
    for (ll i = 0; i < n - numRent; ++i) {
      gallons += prod[i];
    }
    for (ll i = 0; i < m; ++i) {
      if (gallons - sell[i].second <= 0) {
        profit += sell[i].first * gallons;
        break;
      }
      profit += sell[i].first * sell[i].second;
      gallons -= sell[i].second;
    }
    return profit;
  };
  while (l < r) {
    ll m = l + (r - l) / 2;
    ll a = solve(m - 1);
    ll b = solve(m);
    ll c = solve(m + 1);
    if (b >= a && b >= c) {
      cout << b << '\n';
      return 0;
    }
    if (b >= a) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  cout << solve(l) << '\n';
}
