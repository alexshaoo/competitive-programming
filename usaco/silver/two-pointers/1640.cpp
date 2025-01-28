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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    arr[i] = {a, i + 1};
  }
  sort(all(arr));
  int l = 0, r = n - 1;
  while (l < r) {
    if (arr[l].first + arr[r].first == x) {
      cout << arr[l].second << ' ' << arr[r].second << '\n';
      return 0;
    }
    if (arr[l].first + arr[r].first > x) {
      --r;
    } else {
      ++l;
    }
  }
  cout << "IMPOSSIBLE" << '\n';
  return 0;
}
