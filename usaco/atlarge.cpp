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

#define MAXN 100000

vector<int> edges[MAXN];
int distLeaf[MAXN];
int distStart[MAXN];
int ans;

void dfsDistances(int i, int par) {
  distLeaf[i] = MAXN + 1;
  if (par != -1)
    distStart[i] = 1 + distStart[par];
  else
    distStart[i] = 0;
  bool isLeaf = 1;
  for (int j = 0; j < edges[i].size(); j++)
    if (par != edges[i][j]) {
      dfsDistances(edges[i][j], i);
      distLeaf[i] = min(distLeaf[i], 1 + distLeaf[edges[i][j]]);
      isLeaf = 0;
    }
  if (isLeaf) distLeaf[i] = 0;
}

void dfsDistances2(int i, int par) {
  if (par != -1) distLeaf[i] = min(distLeaf[i], distLeaf[par] + 1);
  for (int j = 0; j < edges[i].size(); j++)
    if (par != edges[i][j]) dfsDistances2(edges[i][j], i);
}

void dfs(int i, int par) {
  if ((par != -1) && (distLeaf[i] <= distStart[i]) &&
      (distLeaf[par] > distStart[par])) {
    error(distStart[par], distLeaf[par], distStart[i], distLeaf[i], ' ');
    ans++;
  }
  for (int j = 0; j < edges[i].size(); j++)
    if (edges[i][j] != par) dfs(edges[i][j], i);
}

int main() {
  int K;
  int N, a, b;
  cin >> N >> K;
  K--;
  for (int i = 1; i < N; i++) {
    cin >> a >> b;
    a--, b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  for (int i = K; i < K + 1; i++) {
    if (edges[i].size() == 1) {
      cout << 1 << '\n';
      continue;
    }
    ans = 0;
    dfsDistances(i, -1);
    dfsDistances2(i, -1);
    dfs(i, -1);

    cout << ans << '\n';
  }
}
