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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  vector<int> arr(t);
  for (int i = 0; i < t; ++i) {
    int tmp;
    cin >> tmp;
  }
  for (int i = 0; i < t; ++i) {
    cin >> arr[i];
    ll b = 2;
    ll ans = 1;
    while (arr[i] > 0) {
      if (arr[i] % 2 == 1) {
        ans = (b * ans) % MOD;
      }
      b = (b * b) % MOD;
      arr[i] /= 2;
    }
    cout << ans << '\n';
  }
}
