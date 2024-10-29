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
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

void solve() {
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  ull d = 1;
  ull cost = x;
  ull ans = x + y * z;
  while (z > 0) {
    ull c = y * ((z + d - 1) / d);
    ans = min(ans, c + cost);
    if (d % k == 0) {
      z -= d;
      cost += y;
    }
    ++d;
    cost += x;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
