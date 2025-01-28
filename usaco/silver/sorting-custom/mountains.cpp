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
  setIO("mountains");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<ll, ll>> peak(n);
  for (int i = 0; i < n; ++i) {
    ll x, y;
    cin >> x >> y;
    peak[i] = {x - y, x + y};
  }
  sort(all(peak), [](pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first == b.first) {
      return b.second < a.second;
    }
    return a.first < b.first;
  });
  ll ans = 0;
  ll r = -INT_MAX;
  for (int i = 0; i < n; ++i) {
    if (r < peak[i].second) {
      ++ans;
      r = peak[i].second;
    }
  }
  cout << ans << '\n';
}
