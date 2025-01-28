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

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n), dif(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    if (i == 0) {
      dif[i] = -1;
    } else {
      if (arr[i] == arr[i - 1]) {
        dif[i] = dif[i - 1];
      } else {
        dif[i] = i;
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (dif[r - 1] < l) {
      cout << "-1 -1";
    } else {
      cout << dif[r - 1] << ' ' << r;
    }
    cout << '\n';
  }
  cout << '\n';
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
