#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> pos(n, n + 1);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    pos[x] = i;
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (pos[i - 1] > pos[i])
      ++cnt;
  }
  cout << cnt << '\n';
}
