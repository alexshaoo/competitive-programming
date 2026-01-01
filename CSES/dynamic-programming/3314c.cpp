#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

const int MAXN = 2e5 + 5, INF = INT_MAX;

int h[MAXN], L[MAXN], R[MAXN], dp[MAXN];

int solve(int i) {
  if (h[i] == INF)
    return 0;
  if (dp[i] != -1)
    return dp[i];
  return dp[i] = max(solve(L[i]), solve(R[i])) + 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  fill(dp, dp + n + 2, -1);
  h[0] = h[n + 1] = INF;
  for (int i = 1; i <= n; ++i)
    cin >> h[i];
  stack<int> st;
  st.push(0);
  for (int i = 1; i <= n; ++i) {
    while (h[st.top()] <= h[i])
      st.pop();
    L[i] = st.top();
    st.push(i);
  }
  while (!st.empty())
    st.pop();
  st.push(n + 1);
  for (int i = n; i >= 1; --i) {
    while (h[st.top()] <= h[i])
      st.pop();
    R[i] = st.top();
    st.push(i);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    ans = max(ans, solve(i));
  cout << ans << '\n';
}
