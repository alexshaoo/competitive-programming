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

const int MXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<bool>> arr(n + 1, vector<bool>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char c;
      cin >> c;
      arr[i][j] = (c == '1');
    }
  }
  vector<vector<int>> pre(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + arr[i][j];
    }
  }
  vector<vector<int>> r(n + 1, vector<int>(m + 1)),
      c(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      r[i][j] = r[i - 1][j] + r[i][j - 1] - r[i - 1][j - 1];
      c[i][j] = c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
      if (arr[i][j]) {
        if (arr[i][j - 1]) {
          r[i][j]++;
        }
        if (arr[i - 1][j]) {
          c[i][j]++;
        }
      }
    }
  }
  while (q--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int squares =
        pre[r2][c2] - pre[r1 - 1][c2] - pre[r2][c1 - 1] + pre[r1 - 1][c1 - 1];
    int rc = r[r2][c2] - r[r1 - 1][c2] - r[r2][c1] + r[r1 - 1][c1];
    int cc = c[r2][c2] - c[r1][c2] - c[r2][c1 - 1] + c[r1][c1 - 1];
    cout << squares - rc - cc << '\n';
  }
}
