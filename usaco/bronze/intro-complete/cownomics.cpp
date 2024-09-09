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

int n, m, ans = 0;

int main() {
  setIO("cownomics");
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  char arr[2*n][m];
  for (int i = 0; i < 2*n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < m; ++i) {
    set<char> s;
    bool b = true;
    for (int j = 0; j < n; ++j) s.insert(arr[j][i]);
    for (int j = n; j < 2*n; ++j) if (s.find(arr[j][i]) != s.end()) {
      b = false;
      break;
    }
    ans += b;
  }
  cout << ans << '\n';
}
