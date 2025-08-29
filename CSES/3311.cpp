#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (int r = 0; r < n; ++r) cin >> grid[r];
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      set<int> allowed = {'A', 'B', 'C', 'D'};
      allowed.erase(grid[r][c]);
      if (r != 0) allowed.erase(grid[r - 1][c]);
      if (c != 0) allowed.erase(grid[r][c - 1]);
      grid[r][c] = *allowed.begin();
    }
    cout << grid[r] << '\n';
  }
}
