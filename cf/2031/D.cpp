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
  vector<int> heights(n);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    heights[i] = a;
  }
  vector<int> mx(n), mn(n);
  mx[0] = heights[0];
  mn[n - 1] = heights[n - 1];
  for (int i = 1; i < n; ++i) {
    mx[i] = max(mx[i - 1], heights[i]);
    mn[n - i - 1] = min(mn[n - i], heights[n - i - 1]);
  }
  vector<int> ans(n);
  ans[n - 1] = mx[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    if (mx[i] > mn[i + 1]) {
      ans[i] = ans[i + 1];
    } else {
      ans[i] = mx[i];
    }
  }
  print(all(ans));
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
