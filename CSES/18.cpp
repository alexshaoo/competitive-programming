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

const int MXN = 1e5;
const int MOD = 1e9 + 7;

string s;
int ans = 0;
bool vis[7][7];

bool e(int i, int j) {
  return i >= 0 && j >= 0 && i < 7 && j < 7 && !vis[i][j];
}

void dfs(int i, int j, int p) {
  // done
  if (i == 6 && j == 0) {
    if (p == 48) ++ans;
    return;
  }
  vis[i][j] = 1;
  // try each
  if (s[p] == '?' || s[p] == 'D') {
    if (i < 6 && !vis[i + 1][j]) {
      if (!(!e(i + 2, j) && e(i + 1, j - 1) && e(i + 1, j + 1))) {
        dfs(i + 1, j, p + 1);
      }
    }
  }
  if (s[p] == '?' || s[p] == 'U') {
    if (i && !vis[i - 1][j]) {
      if (!(!e(i - 2, j) && e(i - 1, j - 1) && e(i - 1, j + 1))) {
        dfs(i - 1, j, p + 1);
      }
    }
  }
  if (s[p] == '?' || s[p] == 'L') {
    if (j && !vis[i][j - 1]) {
      if (!(!e(i, j - 2) && e(i - 1, j - 1) && e(i + 1, j - 1))) {
        dfs(i, j - 1, p + 1);
      }
    }
  }
  if (s[p] == '?' || s[p] == 'R') {
    if (j < 6 && !vis[i][j + 1]) {
      if (!(!e(i, j + 2) && e(i - 1, j + 1) && e(i + 1, j + 1))) {
        dfs(i, j + 1, p + 1);
      }
    }
  }
  vis[i][j] = 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> s;
  dfs(0, 0, 0);
  cout << ans << '\n';
}
