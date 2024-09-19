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

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

#define ll long long
#define all(x) (x).begin(), (x).end()

const int MXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, ans = 0;

int main() {
  setIO("planting");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<int> deg(n+1);
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    cin >> u >> v;
    ++deg[u];
    ++deg[v];
    ans = max(ans, max(deg[u], deg[v]));
  }
  cout << ans+1 << '\n';
}
