#include <bits/stdc++.h>
using namespace std;

template <typename T, size_t SIZE>
void print(const T (&array)[SIZE]) {
  for (size_t i = 0; i < SIZE; i++) std::cout << array[i] << " ";
}

template <class ForwardIter>
void print(ForwardIter begin, ForwardIter end) {
  for (; begin != end; ++begin) cout << *begin << " ";
  cout << endl;
}

#define ll long long

const int MXN = 1e4 + 5;
const int MOD = 1e9 + 7;

int ans = 0;
bool f[MXN][MXN];

void dfs(int i, int j) {
  if (!f[i][j]) return;
  f[i][j] = 0;
  dfs(i - 1, j);
  dfs(i + 1, j);
  dfs(i, j - 1);
  dfs(i, j + 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  char c;
  memset(f, 0, sizeof(f));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> c;
      if (c == '.') f[i][j] = 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (f[i][j]) {
        ++ans;
        dfs(i, j);
      }
    }
  }
  cout << ans << '\n';
}
