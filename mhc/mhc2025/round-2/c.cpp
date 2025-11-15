#include <bits/stdc++.h>
using namespace std;

template <typename T, size_t SIZE> void print(const T (&array)[SIZE]) {
  for (size_t i = 0; i < SIZE; i++)
    cout << array[i] << " ";
  cout << '\n';
}

template <class ForwardIter> void print(ForwardIter begin, ForwardIter end) {
  for (; begin != end; ++begin)
    cout << *begin << " ";
  cout << '\n';
}

#define ll long long
#define all(x) (x).begin(), (x).end()

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

struct DSU {
  vector<int> parent;
  DSU() {}
  DSU(int n) { init(n); }
  void init(int n) {
    parent.resize(n + 1);
    for (int i = 0; i <= n; ++i)
      parent[i] = i;
  }
  int find(int x) { return parent[x] == x ? x : (parent[x] = find(parent[x])); }
  void erasePos(int p) { parent[p] = find(p + 1); }
};

void test_case() {
  int n, k, m;
  cin >> n >> k >> m;
  vector<vector<pair<int, int>>> occ(n +
                                     1); // occ[i] for court i is (route, pos)
  vector<vector<int>> routes(m);
  vector<DSU> dsu(m);
  for (int r = 0; r < m; ++r) {
    int L;
    cin >> L;
    routes[r].resize(L);
    for (int j = 0; j < L; ++j) {
      int l;
      cin >> l;
      routes[r][j] = l;
      occ[l].push_back({r, j});
    }
    dsu[r].init(L);
  }
  vector<ll> dist(n + 1, -1);
  queue<int> q;

  dist[1] = 0;
  q.push(1);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    ll d = dist[cur];
    auto &listOcc = occ[cur];
    for (auto [r, p] : listOcc) {
      int L = routes[r].size();
      int maxPos = L - 1;
      int limit = min(maxPos, p + k);
      for (int qpos = dsu[r].find(p + 1); qpos <= limit;
           qpos = dsu[r].find(qpos + 1)) {
        int court = routes[r][qpos];
        if (dist[court] == -1) {
          dist[court] = d + 1;
          q.push(court);
        }
        dsu[r].erasePos(qpos);
      }
    }
    listOcc.clear();
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += dist[i] * i;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    test_case();
  }
  return 0;
}
