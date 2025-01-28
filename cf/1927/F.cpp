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

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

class DSU {
 private:
  int par[MAXN];

 public:
  DSU() { iota(par, par + MAXN, 0); }
  int rep(int v) {
    while (par[v] != v) {
      v = par[v];
    }
    return v;
  }
  void onion(int u, int v) { par[rep(u)] = rep(v); }
  bool same(int u, int v) { return rep(u) == rep(v); }
};

unordered_map<int, unordered_set<int>> cycleEdges;
int parent[MAXN] = {0},
    status[MAXN] = {0};  // 0 not visited, 1 visting, 2 visited
void dfs(int u, unordered_map<int, unordered_set<int>>& cycleEdges) {
  status[u] = 1;
  for (auto it = cycleEdges[u].begin(); it != cycleEdges[u].end(); ++it) {
    int v = *it;
    if (status[v] == 0) {
      parent[v] = u;
      dfs(v, cycleEdges);
    } else if (status[v] == 1 && v != parent[u]) {
      cout << "HAPPEN" << '\n';
      int len = 0;
      vector<int> cycle;
      while (u != v) {
        cycle.push_back(u);
        ++len;
        u = parent[u];
      }
      cout << len + 1 << '\n';
      print(all(cycle));
    }
  }
  status[u] = 2;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> edges(m);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[i] = {w, u, v};
  }
  DSU dsu;
  sort(all(edges));
  int minw = INT_MAX;
  set<int> tmp;
  for (const auto& [w, u, v] : edges) {
    tmp.insert(u);
    tmp.insert(v);
    if (dsu.same(u, v)) {  // find cycle
      unordered_map<int, int> parentMap;
      parentMap[u] = -1;
      for (auto it = tmp.begin(); it != tmp.end(); ++it) {
        cout << *it << ' ';
      }
      cout << '\n';
      cout << minw << ' ';
      cout << '\n';
      dfs(u, cycleEdges);
      break;
    } else {
      cycleEdges[u].insert(v);
      cycleEdges[v].insert(u);
      minw = min(minw, w);
      dsu.onion(u, v);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
