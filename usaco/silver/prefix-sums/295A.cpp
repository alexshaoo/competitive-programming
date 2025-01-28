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

int main() {
  // setIO("");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<ll> arr(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  vector<tuple<int, int, int>> operations(m + 1);
  for (int i = 1; i <= m; ++i) {
    int l, r, d;
    cin >> l >> r >> d;
    operations[i] = {l, r, d};
  }
  vector<ll> queries(m + 2);
  while (k--) {
    int x, y;
    cin >> x >> y;
    queries[x]++;
    queries[y + 1]--;
  }
  for (int i = 1; i <= m; ++i) {
    queries[i] += queries[i - 1];
  }
  vector<ll> delta(n + 2);
  for (int i = 1; i <= m; ++i) {
    auto &[l, r, d] = operations[i];
    delta[l] += d * queries[i];
    delta[r + 1] -= d * queries[i];
  }
  for (int i = 1; i <= n; ++i) {
    delta[i] += delta[i - 1];
    arr[i] += delta[i];
    cout << arr[i] << ' ';
  }
}
// took so many attempts because i got the array bounds wrong
