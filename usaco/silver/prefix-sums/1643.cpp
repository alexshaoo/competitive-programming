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
#define all(x) (x).begin(), (x).end()

const int MXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, ans = -INT_MAX;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  vector<int> pre(n);
  pre[0] = arr[0];
  for (int i = 1; i < n; ++i) {
    pre[i] = pre[i-1] + arr[i];
  }
  int mn = 0;
  for (int i = 1; i < n; ++i) {
    ans = max(ans, pre[i]-mn);
    mn = min(mn, pre[i]);
  }
  print(all(pre));
  cout << ans << '\n';
}
