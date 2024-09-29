#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f
#define LLINF 0x3f3f3f3f

struct q {
  int i, c, l;
  bool operator<(const q &o) { return l < o.l; }
};

const int MAX = 2001, MAXV = 100001, MAXX = 10001;
int N, V, cj, lj, qq = 0, coin[MAX], dp[MAXX], ans[MAXV];
h q queries[MAXV];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> V;
  for (int i = 1; i <= N; ++i) {
    cin >> coin[i];
  }
  for (int i = 0; i < V; ++i) {
    cin >> cj >> lj;
    queries[i] = {i, cj, lj};
  }
  sort(queries, queries + V);
  memset(dp, INF, sizeof dp);
  dp[0] = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = coin[i]; j < MAXX; ++j) {
      dp[j] = min(dp[j], dp[j - coin[i]] + 1);
    }
    while (qq < V && queries[qq].l == i) {
      int cans = dp[queries[qq].c];
      ans[queries[qq].i] = (cans == LLINF) ? -1 : cans;
      qq++;
    }
  }
  for (int i = 0; i < V; ++i) {
    printf("%d\n", ans[i]);
  }
}