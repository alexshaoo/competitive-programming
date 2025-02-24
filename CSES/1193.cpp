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
  int sr, sc, er, ec;
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'A') {
        sr = i;
        sc = j;
      } else if (grid[i][j] == 'B') {
        er = i;
        ec = j;
      }
    }
  }
  const array<tuple<int, int, string>, 4> dirs = {
      make_tuple(-1, 0, "U"), make_tuple(1, 0, "D"), make_tuple(0, -1, "L"),
      make_tuple(0, 1, "R")};
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  auto bounds = [&](int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
  };
  queue<tuple<int, int, string>> q;  // r, c, path
  q.push({sr, sc, ""});
  while (!q.empty()) {
    auto [r, c, path] = q.front();
    q.pop();
    for (auto [dr, dc, dpath] : dirs) {
      int nr = r + dr, nc = c + dc;
      string npath = path + dpath;
      if (bounds(nr, nc) && grid[nr][nc] != '#' && !visited[nr][nc]) {
        if (nr == er && nc == ec) {
          cout << "YES" << '\n';
          cout << sz(npath) << '\n';
          cout << npath << '\n';
          return 0;
        }
        visited[nr][nc] = true;
        q.push({nr, nc, npath});
      }
    }
  }
  cout << "NO" << '\n';
}
