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

const int MXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int n;
int ans[MXN];
vector<int> adj[MXN];

void dfs(int u) {
  ans[u] = 1;
  for (int v : adj[u]) {
    dfs(v);
    ans[u] += ans[v];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    adj[p - 1].push_back(i);
  }
  dfs(0);
  for (int i = 0; i < n; ++i) {
    cout << ans[i] - 1 << ' ';
  }
  cout << '\n';
}
