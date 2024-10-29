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
  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].first >> arr[i].second;
  }
  sort(all(arr), [](pair<int, int> a, pair<int, int> b) {
    return a.first + a.second < b.first + b.second;
  });
  for (auto [a, b] : arr) {
    cout << a << ' ' << b << ' ';
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
