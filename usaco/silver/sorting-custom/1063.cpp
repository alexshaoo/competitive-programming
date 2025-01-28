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

const int MAXN = 2e3 + 5;
const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> coords(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    coords[i] = {x, y};
  }
  sort(all(coords));
  for (int i = 0; i < n; ++i) {
    coords[i].first = i;
  }
  sort(all(coords),
       [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
  for (int i = 0; i < n; ++i) {
    coords[i].second = i;
  }
  vector<vector<int>> ps(n + 1, vector<int>(n + 1));
  for (int i = 0; i < n; ++i) {
    ps[coords[i].first + 1][coords[i].second + 1] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      ps[i][j] += ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
    }
  }
  ll ans = 1;
  auto f = [&](int x1, int y1, int x2, int y2) {
    return ps[x2][y2] - ps[x2][y1 - 1] - ps[x1 - 1][y2] + ps[x1 - 1][y1 - 1];
  };
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int xl = min(coords[i].first, coords[j].first);
      int xr = max(coords[i].first, coords[j].first);
      ans += f(1, i + 1, xl + 1, j + 1) * f(xr + 1, i + 1, n, j + 1);
    }
  }
  cout << ans << '\n';
}
