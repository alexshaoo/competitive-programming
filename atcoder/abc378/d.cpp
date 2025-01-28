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

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int H, W, K;

vector<pii> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool inBounds(int& r, int& c) { return r >= 0 && r < H && c >= 0 && c < W; }

void dfs(int r, int c, int& count, int depth, vector<string>& grid,
         vector<vector<bool>>& vis) {
  if (depth == 0) {
    ++count;
    return;
  }
  vis[r][c] = true;
  for (auto& [dr, dc] : dirs) {
    int nr = r + dr;
    int nc = c + dc;
    if (inBounds(nr, nc) && !vis[nr][nc] && grid[nr][nc] == '.') {
      dfs(nr, nc, count, depth - 1, grid, vis);
    }
  }
  vis[r][c] = false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> H >> W >> K;
  vector<string> grid(H);
  for (int i = 0; i < H; ++i) {
    cin >> grid[i];
  }
  int count = 0;
  vector<vector<bool>> vis(H, vector<bool>(W));
  for (int r = 0; r < H; ++r) {
    for (int c = 0; c < W; ++c) {
      if (grid[r][c] != '#') {
        dfs(r, c, count, K, grid, vis);
      }
    }
  }
  cout << count << '\n';
}
