#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

void f(int n, vector<vector<int>>& grid, int row, int col) {
  vector<int> v(2 * (n - 1));
  iota(all(v), 1);
  set<int> s(all(v));
  for (int r = 0; r < row; ++r) {
    s.erase(grid[r][col]);
  }
  for (int c = 0; c < col; ++c) {
    s.erase(grid[row][c]);
  }
  grid[row][col] = *s.begin();
  grid[col][row] = *s.begin();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n, 0));
  for (int r = 0; r < n - 1; ++r) {
    for (int c = r + 1; c < n; ++c) {
      f(n, grid, r, c);
    }
  }
  for (auto v : grid) {
    for (auto num : v) {
      cout << num << ' ';
    }
    cout << '\n';
  }
}
