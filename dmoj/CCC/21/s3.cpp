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

#define ll long long
#define all(x) (x).begin(), (x).end()

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

ll f(vector<array<ll, 3>>& arr, ll m) {
  ll res = 0;
  for (const auto& [p, w, d] : arr) {
    if (abs(m - p) > d) {
      res += w * (abs(m - p) - d);
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  vector<array<ll, 3>> arr(n);
  for (ll i = 0; i < n; ++i) {
    ll p, w, d;
    cin >> p >> w >> d;
    arr[i] = {p, w, d};
  }
  sort(all(arr));
  ll l = 0;
  ll r = MOD;
  while (l < r) {
    ll m = l + (r - l) / 2;
    ll a = f(arr, m - 1);
    ll b = f(arr, m);
    ll c = f(arr, m + 1);
    if (a >= b && c >= b) {
      cout << b << '\n';
      return 0;
    }
    if (a >= b) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << f(arr, l) << '\n';
  return 0;
}
