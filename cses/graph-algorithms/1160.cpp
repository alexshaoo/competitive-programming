#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

const int JUMP_LIMIT = 20;

struct DSU {
  vector<int> par;
  vector<int> heights;
  DSU(int n) {
    heights.assign(n + 1, 0);
    par.resize(n + 1);
    iota(all(par), 0);
  }
  int find(int x) { // find component of x
    if (par[x] == x)
      return x;
    return par[x] = find(par[x]);
  }
  void unite(int a, int b) { // a -> b
    int ra = find(a), rb = find(b);
    if (ra == rb)
      return;
    if (heights[ra] < heights[rb])
      swap(ra, rb);
    par[rb] = ra;
    if (heights[ra] == heights[rb])
      heights[ra]++;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;

  DSU dsu(n);

  vector<int> destinations(n);
  int t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    destinations[i] = t;
    dsu.unite(i + 1, t);
  }

  vector<int> state(n + 1, 0), depth(n + 1, -1);
  vector<int> cycleSize(n + 1, -1), cyclePos(n + 1, -1);
  auto dfs = [&](auto &self, int curr) -> void {
    state[curr] = 1;
    int nxt = destinations[curr - 1];
    if (state[nxt] == 0) {
      self(self, nxt);
    } else if (state[nxt] == 1) { // cycle detected
      int size = 0;
      int tmp = nxt;
      do {
        ++size;
        tmp = destinations[tmp - 1];
      } while (tmp != nxt);
      tmp = nxt;
      int pos = 0;
      do {
        depth[tmp] = 0;
        cycleSize[tmp] = size;
        cyclePos[tmp] = pos++;
        tmp = destinations[tmp - 1];
      } while (tmp != nxt);
    }
    if (state[nxt] == 2 && depth[curr] == -1) {
      depth[curr] = depth[nxt] + 1;
    }
    state[curr] = 2;
  };

  for (int i = 1; i <= n; ++i) {
    if (state[i] == 0)
      dfs(dfs, i);
  }

  // taken from planet queries I, problem 1750
  // dp[i][j] is planet you end up on from planet i with j jumps
  vector<vector<int>> dp(n + 1, vector<int>(JUMP_LIMIT + 1, 0));
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = destinations[i - 1];
  }
  for (int j = 1; j <= JUMP_LIMIT; ++j) {
    for (int i = 1; i <= n; ++i) {
      int nxt = dp[i][j - 1];
      dp[i][j] = dp[nxt][j - 1];
    }
  }

  auto jump = [&](int node, int steps) {
    for (int i = 0; i < JUMP_LIMIT; ++i) {
      if (steps & (1 << i)) {
        node = dp[node][i];
      }
    }
    return node;
  };

  // functional/successor graph
  while (q--) {
    int a, b;
    cin >> a >> b;
    // a, b not in same component
    if (dsu.find(a) != dsu.find(b)) {
      cout << "-1" << '\n';
      continue;
    }
    // b in cycle
    if (depth[b] == 0) {
      int rootA = jump(a, depth[a]);
      int size = cycleSize[b];
      cout << depth[a] + (cyclePos[b] - cyclePos[rootA] + size) % size << '\n';
      continue;
    }
    // NOT (b in same tree as a, closer to cycle)
    if (depth[a] < depth[b]) {
      cout << "-1" << '\n';
    } else {
      int dist = depth[a] - depth[b];
      if (jump(a, dist) == b)
        cout << dist;
      else
        cout << "-1";
      cout << '\n';
    }
  }
}
