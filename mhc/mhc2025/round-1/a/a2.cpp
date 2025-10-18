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

#define ll long long
#define all(x) (x).begin(), (x).end()

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

struct DSU {
  vector<int> p, r;
  DSU(int n) {
    p.resize(n);
    r.resize(n);
    iota(all(p), 0);
  }
  int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
  }
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (r[a] < r[b]) swap(a, b);
    p[b] = a;
    if (r[a] == r[b]) ++r[a];
    return true;
  }
};

void test_case() {
  int ans = 0;
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) cin >> A[i];
  vector<array<int, 3>> edges; // length, u, v
  for (int i = 0; i < n-1; ++i) {
    edges.push_back({abs(A[i+1] - A[i]), i+1, i+2});
  }
  for (int i = 0; i < n; ++i) {
    edges.push_back({A[i], 0, i+1});
  }
  sort(all(edges));
  DSU dsu(n+1);
  int components = n+1;
  for (const auto& edge : edges) {
    if (dsu.unite(edge[1], edge[2])) {
      ans = max(ans, edge[0]);
      --components;
      if (components == 1) break;
    }
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
