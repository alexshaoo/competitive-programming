#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  int B = max(1, (int)sqrt(n));
  int numBlocks = (n + B - 1) / B; // ceiling

  vector<vector<int>> blocks(numBlocks);
  for (int i = 0; i < n; ++i) {
    blocks[i / B].push_back(i + 1);
  }

  ll pos = 0;
  for (int i = 0; i < n; ++i) {
    pos = (pos + k) % (n - i);
    ll p = pos;
    int bi = 0;
    while (p >= (int)blocks[bi].size()) {
      p -= (int)blocks[bi].size();
      ++bi;
    }
    cout << blocks[bi][p] << ' ';
    blocks[bi].erase(blocks[bi].begin() + p);
  }
}
