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
  vector<int> tmp = {0, 1, 0, -1, 0};
  string dirs = "RDLU";
  unordered_map<char, pair<int, int>> dirDelta;
  for (int i = 0; i < 4; ++i) {
    dirDelta[dirs[i]] = {tmp[i], tmp[i + 1]};
  }
  unordered_map<char, char> oppDir;
  for (int i = 0; i < 4; ++i) {
    oppDir[dirs[i]] = dirs[(i + 2) % 4];
  }
  vector<string> grid(n);
  queue<array<int, 3>> q, mq; // my queue, monster Q, {row, col, time}
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'M')
        mq.push({i, j, 0});
      else if (grid[i][j] == 'A')
        q.push({i, j, 0});
    }
  }
  vector<vector<char>> par(n, vector<char>(m, '?'));
  vector<vector<int>> monsterTime(n, vector<int>(m, INT_MAX));
  auto check = [&](int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != '#';
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'M')
        monsterTime[i][j] = 0;
    }
  }
  while (!mq.empty()) {
    auto [r, c, time] = mq.front();
    mq.pop();
    for (char dir : dirs) {
      auto [dr, dc] = dirDelta[dir];
      int nr = r + dr, nc = c + dc;
      if (check(nr, nc) && time + 1 < monsterTime[nr][nc]) {
        monsterTime[nr][nc] = time + 1;
        mq.push({nr, nc, time + 1});
      }
    }
  }
  vector<vector<int>> myTime(n, vector<int>(m, INT_MAX));
  auto [sr, sc, st] = q.front();
  myTime[sr][sc] = 0;
  while (!q.empty()) {
    auto [r, c, time] = q.front();
    q.pop();
    for (char dir : dirs) {
      auto [dr, dc] = dirDelta[dir];
      int nr = r + dr, nc = c + dc;
      if (check(nr, nc) && time + 1 < monsterTime[nr][nc] && myTime[nr][nc] == INT_MAX) {
        myTime[nr][nc] = time + 1;
        par[nr][nc] = oppDir[dir];
        q.push({nr, nc, time + 1});
      }
    }
  }
  auto found = [&](int r, int c) {
    cout << "YES\n";
    int cr = r, cc = c;
    string path;
    while (par[cr][cc] != '?') {
      char dir = par[cr][cc];
      path.push_back(oppDir[dir]);
      auto [dr, dc] = dirDelta[dir];
      cr += dr;
      cc += dc;
    }
    reverse(all(path));
    cout << path.length() << '\n';
    cout << path << '\n';
  };
  for (int r : {0, n - 1}) {
    for (int c = 0; c < m; ++c) {
      if (myTime[r][c] != INT_MAX && myTime[r][c] < monsterTime[r][c]) {
        found(r, c);
        return 0;
      }
    }
  }
  for (int c : {0, m - 1}) {
    for (int r = 0; r < n; ++r) {
      if (myTime[r][c] != INT_MAX && myTime[r][c] < monsterTime[r][c]) {
        found(r, c);
        return 0;
      }
    }
  }
  cout << "NO\n";
}
