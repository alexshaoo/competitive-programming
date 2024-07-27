#include <bits/stdc++.h>
using namespace std;

#define error(args...)                       \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
  }

void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}

template <typename T, size_t SIZE>
void print(const T (&array)[SIZE]) {
  for (size_t i = 0; i < SIZE; i++) cout << array[i] << " ";
  cout << '\n';
}

template <typename T>
void print(const vector<T>& vec) {
  for (const auto& elem : vec) {
    cout << elem << " ";
  }
  cout << endl;
}

#define ll long long

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, k;
int ans = 0;

void bfs1(vector<vector<int>>& adj, vector<int>& dist, deque<int>& q) {
  vector<bool> vis(n + 1, false);
  while (!q.empty()) {
    int u = q.back();
    q.pop_back();
    vis[u] = true;
    for (const auto& v : adj[u]) {
      if (!vis[v]) {
        dist[v] = dist[u] + 1;
        q.push_front(v);
      }
    }
  }
  return;
}

void bfs2(int& ans, vector<vector<int>>& adj, deque<int>& q, vector<int>& db,
          vector<int>& de) {
  vector<bool> vis(n + 1, false);
  while (!q.empty()) {
    int u = q.back();
    q.pop_back();
    vis[u] = true;
    for (const auto& v : adj[u]) {
      if (!vis[v]) {
        vis[v] = true;
        if (db[v] >= de[v] && db[u] < de[u]) {
          error(db[u], de[u], db[v], de[v], ' ');
          ++ans;
        } else {
          q.push_front(v);
        }
      }
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("atlarge.in", "r", stdin);
  // freopen("atlarge.out", "w", stdout);
  cin >> n >> k;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> db(n + 1, MAXN), de(n + 1, MAXN);
  deque<int> bq, eq;
  bq.push_front(k);
  db[k] = 0;
  bfs1(adj, db, bq);
  for (int i = 1; i <= n; ++i) {
    if (adj[i].size() == 1) {
      eq.push_front(i);
      de[i] = 0;
    }
  }
  bfs1(adj, de, eq);
  // print(db);
  // print(de);
  deque<int> q;
  q.push_front(k);
  bfs2(ans, adj, q, db, de);
  cout << ans << '\n';
}
