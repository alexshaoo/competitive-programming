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

int t, n, ans = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    int num;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    ans = 0;
    vector<int> pre(n), suf(n);
    for (int i = 0; i < n; ++i) {
      pre[i] = arr[i] + i;
      suf[i] = arr[i] - i;
    }
    for (int i = 1; i < n; ++i) {
      pre[i] = max(pre[i], pre[i-1]);
    }
    for (int i = n-2; i >= 0; --i) {
      suf[i] = max(suf[i], suf[i+1]);
    }
    for (int i = 1; i < n-1; ++i) {
      ans = max(ans, arr[i] + pre[i-1] + suf[i+1]);
    }
    cout << ans << '\n';
  }
}
