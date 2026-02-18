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
  vector<int> x(n), pos(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
    pos[x[i]] = i;
  }
  int rounds = 1;
  for (int i = 1; i < n; ++i) {
    if (pos[i] > pos[i + 1])
      ++rounds;
  }
  auto countInversions = [&](int i, int j) {
    if (x[i] > x[j])
      swap(i, j);
    int inv = 0;
    if (x[i] > 1 && pos[x[i] - 1] > pos[x[i]])
      ++inv;
    if (x[i] < n && pos[x[i] + 1] < pos[x[i]])
      ++inv;
    if (abs(x[i] - x[j]) != 1) {
      if (x[j] > 1 && pos[x[j] - 1] > pos[x[j]])
        ++inv;
    }
    if (x[j] < n && pos[x[j] + 1] < pos[x[j]])
      ++inv;
    return inv;
  };
  while (m--) {
    int i, j;
    cin >> i >> j;
    --i;
    --j;
    int before = countInversions(i, j);
    swap(x[i], x[j]);
    swap(pos[x[i]], pos[x[j]]);
    int after = countInversions(i, j);
    rounds += (after - before);
    cout << rounds << '\n';
  }
}
