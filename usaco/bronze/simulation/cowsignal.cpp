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

int m, n, k;
int ans = 0;

int main() {
  setIO("cowsignal");
  ios_base::sync_with_stdio(0);
  cin >> m >> n >> k;
  char ans[k * m][k * n];
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      char c;
      cin >> c;
      for (int x = k * i; x < k * (i + 1); ++x) {
        for (int y = k * j; y < k * (j + 1); ++y) {
          ans[x][y] = c;
        }
      }
    }
  }
  for (int i = 0; i < k * m; ++i) {
    for (int j = 0; j < k * n; ++j) {
      cout << ans[i][j];
      if (j == k * n - 1) cout << '\n';
    }
  }
}
