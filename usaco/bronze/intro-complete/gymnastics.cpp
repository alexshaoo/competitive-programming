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

int k, n, ans = 0;

int main() {
  setIO("gymnastics");
  ios_base::sync_with_stdio(0);
  cin >> k >> n;
  int arr[k][n], ind[k][n];
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
      --arr[i][j];
      ind[i][arr[i][j]] = j;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      bool c1 = true, c2 = true;
      for (int s = 0; s < k; ++s) {
        int c1p = ind[s][i];
        int c2p = ind[s][j];
        if (c1p < c2p) c1 = false;
        if (c1p > c2p) c2 = false;
      }
      ans += c1 || c2;
    }
  }
  cout << ans << '\n';
}
