#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

vector<pair<int, int>> validMoves = {{-2, -1}, {-2, 1}, {-1, 2},  {1, 2},
                                     {2, 1},   {2, -1}, {-1, -2}, {1, -2}};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> chessboard(n, vector<int>(n, INT_MAX));
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  queue<tuple<int, int, int>> q;  // r, c, numMoves
  q.push({0, 0, 0});
  while (!q.empty()) {
    auto [r, c, moves] = q.front();
    q.pop();
    if (r >= 0 && r < n && c >= 0 && c < n && !visited[r][c]) {
      chessboard[r][c] = moves;
      visited[r][c] = true;
      for (const auto& [dr, dc] : validMoves) {
        q.push({r + dr, c + dc, moves + 1});
      }
    }
  }
  for (auto r : chessboard) {
    for (auto c : r) {
      cout << c << ' ';
    }
    cout << '\n';
  }
}
