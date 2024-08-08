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

const int MXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, m;
int ans = 0;

int main() {
  setIO("speeding");
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  vector<pair<int, int>> road, speeds;
  for (int i = 0; i < n; ++i) {
    pair<int, int> p;
    cin >> p.first >> p.second;
    road.push_back(p);
  }
  for (int i = 0; i < m; ++i) {
    pair<int, int> p;
    cin >> p.first >> p.second;
    speeds.push_back(p);
  }
  int l = 0;
  int r = 0, s = 0;
  while (l++ < 100) {
    if (road[r].first == 0) ++r;
    if (speeds[s].first == 0) ++s;
    ans = max(ans, speeds[s].second - road[r].second);
    road[r].first--;
    speeds[s].first--;
  }
  cout << ans << '\n';
}
