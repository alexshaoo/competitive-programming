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
  vector<int> x(n), pos(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
    pos[x[i]] = i;
  }
  int rounds = 1;
  for (int i = 0; i < n - 1; ++i) {
    if (pos[i] > pos[i + 1])
      ++rounds;
  }
  cout << rounds << '\n';
  while (m--) {
    int u, v;
    cin >> u >> v;
  }
}
