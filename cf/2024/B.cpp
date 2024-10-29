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

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(all(arr));
  ll have = 0, att = 0, start = 0, taken = 0;
  while (1) {
    int presses = arr[start] - taken;
    if (have + presses * (n - start) < k) {
      have += presses * (n - start);
      att += presses * (n - start);
      taken = arr[start];
      while (start < n && taken == arr[start]) {
        ++att;
        ++start;
      }
    } else {
      cout << att + (k - have) << '\n';
      return;
    }
  }
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
