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

const int MXN = 101;
const int MOD = 1e9 + 7;

int n, m, ans = INT_MAX;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  vector<int> cows(MXN);
  while (n--) {
    int s, t, c;
    cin >> s >> t >> c;
    for (int j = s; j <= t; ++j) cows[j] = c;
  }
  vector<vector<int>> conditioners;
  for (int i = 0; i < m; ++i) {
		int a, b, p, m;
		cin >> a >> b >> p >> m;
    conditioners.push_back({a, b, p, m});
  }
  for (int mask = 0; mask < (1 << m); ++mask) {
    vector<int> cooling(MXN);
    int price = 0;
    for (int i = 0; i < m; ++i) {
      if (mask & (1 << i)) {
        for (int j = conditioners[i][0]; j <= conditioners[i][1]; ++j) cooling[j] += conditioners[i][2];
        price += conditioners[i][3];
      }
    }
    bool cool = true;
    for (int i = 0; i < MXN; ++i) {
      if (cows[i] > cooling[i]) {
        cool = false;
        break;
      }
    }
    if (cool) ans = min(ans, price);
  }
  cout << ans << '\n';
}
