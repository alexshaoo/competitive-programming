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

const int MAXN = 5e4 + 5;
const int MAXC = 1e9 + 5;

int main() {
  setIO("split");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<ll, ll>> pos(n);
  pair<ll, ll> width = {MAXC, 0}, height = {MAXC, 0};
  for (int i = 0; i < n; ++i) {
    ll x, y;
    cin >> x >> y;
    pos[i] = {x, y};
    width = {min(width.first, x), max(width.second, x)};
    height = {min(height.first, y), max(height.second, y)};
  }
  ll newArea = LLONG_MAX;
  auto f = [&]() {
    sort(all(pos));
    unordered_map<ll, ll> left, right;
    ll d = MAXC, u = 0;
    for (int i = 0; i < n; ++i) {
      d = min(d, pos[i].second);
      u = max(u, pos[i].second);
      left[pos[i].first] =
          max(left[pos[i].first], (pos[i].first - pos[0].first) * (u - d));
    }
    d = MAXC, u = 0;
    for (int i = n - 1; i >= 0; --i) {
      d = min(d, pos[i].second);
      u = max(u, pos[i].second);
      right[pos[i].first] =
          max(right[pos[i].first], (pos[n - 1].first - pos[i].first) * (u - d));
    }
    for (int i = 0; i < n - 1; ++i) {
      newArea = min(newArea, left[pos[i].first] + right[pos[i + 1].first]);
    }
  };
  f();
  for (auto& [x, y] : pos) {
    swap(x, y);
  }
  f();
  ll oldArea = (width.second - width.first) * (height.second - height.first);
  cout << oldArea - newArea << '\n';
}
