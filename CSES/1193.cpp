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
  const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  string paths = "UDLR";
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  vector<vector<int>> pre(n, vector<int>(m, -1));
  auto bounds = [&](int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
  };
  queue<pair<int, int>> q;  // r, c
  q.push({sr, sc});
  visited[sr][sc] = true;
  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();
    for (int d = 0; d < 4; ++d) {
      int nr = r + dirs[d].first, nc = c + dirs[d].second;
      if (bounds(nr, nc) && grid[nr][nc] != '#' && !visited[nr][nc]) {
        visited[nr][nc] = true;
        q.push({nr, nc});
        pre[nr][nc] = d;
        if (nr == er && nc == ec) {
          string path;
          while (nr != sr || nc != sc) {
            int i = pre[nr][nc];
            path += paths[i];
            nr -= dirs[i].first;
            nc -= dirs[i].second;
          }
          reverse(all(path));
          cout << "YES" << '\n';
          cout << sz(path) << '\n';
          cout << path << '\n';
          return 0;
        }
      }
    }
  }
  cout << "NO" << '\n';
}
