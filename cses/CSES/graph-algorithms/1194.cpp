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
  vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  string dirChars = "RDLU";
  vector<string> grid(n);
  int sr = -1, sc = -1;
  queue<pair<int, int>> mq;
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'M')
        mq.push({i, j});
      else if (grid[i][j] == 'A') {
        sr = i;
        sc = j;
      }
    }
  }
  // bfs monster
  vector<vector<int>> monsterDist(n, vector<int>(m, INT_MAX));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'M')
        monsterDist[i][j] = 0;
    }
  }
  while (!mq.empty()) {
    auto [r, c] = mq.front();
    mq.pop();
    for (int d = 0; d < 4; ++d) {
      int nr = r + dirs[d].first, nc = c + dirs[d].second;
      if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' &&
          monsterDist[r][c] + 1 < monsterDist[nr][nc]) {
        monsterDist[nr][nc] = monsterDist[r][c] + 1;
        mq.push({nr, nc});
      }
    }
  }
  // my bfs
  vector<vector<int>> myDist(n, vector<int>(m, INT_MAX)),
      parent(n, vector<int>(m, -1));
  queue<pair<int, int>> q;
  q.push({sr, sc});
  myDist[sr][sc] = 0;
  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();
    for (int d = 0; d < 4; ++d) {
      int nr = r + dirs[d].first, nc = c + dirs[d].second;
      if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' &&
          myDist[r][c] + 1 < monsterDist[nr][nc] && myDist[nr][nc] == INT_MAX) {
        myDist[nr][nc] = myDist[r][c] + 1;
        parent[nr][nc] = d;
        q.push({nr, nc});
      }
    }
  }
  // check boundary cells
  int er = -1, ec = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) &&
          myDist[i][j] < monsterDist[i][j]) {
        er = i;
        ec = j;
        break;
      }
    }
    if (er != -1)
      break;
  }
  if (er == -1) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  string path;
  int cr = er, cc = ec;
  while (cr != sr || cc != sc) {
    int d = parent[cr][cc];
    path += dirChars[d];
    cr -= dirs[d].first;
    cc -= dirs[d].second;
  }
  reverse(all(path));
  cout << sz(path) << '\n';
  cout << path << '\n';
}
