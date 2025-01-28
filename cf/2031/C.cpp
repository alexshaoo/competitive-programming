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

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    for (int i = 1; i <= n / 2; ++i) {
      cout << i << ' ' << i << ' ';
    }
    cout << '\n';
  } else {
    if (n < 27) {
      cout << -1 << '\n';
      return;
    }
    vector<int> ans(n, -1);
    ans[0] = 1;
    ans[9] = 1;
    ans[25] = 1;
    ans[26] = 2;
    ans[22] = 2;
    int filling = 3;
    for (int i = 0; i < n; ++i) {
      if (ans[i] != -1) continue;
      ans[i] = filling;
      ans[i + 1] = filling++;
    }
    print(all(ans));
  }
  return;
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
