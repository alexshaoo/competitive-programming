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
  if (n < 3) {
    cout << "IMPOSSIBLE" << '\n';
    return 0;
  }
  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    arr[i] = {a, i + 1};
  }
  sort(all(arr));
  auto f = [&](int target, int l) -> pair<int, int> {
    int r = n - 1;
    while (l < r) {
      if (arr[l].first + arr[r].first == target) {
        return {arr[l].second, arr[r].second};
      }
      if (arr[l].first + arr[r].first > target) {
        --r;
      } else {
        ++l;
      }
    }
    return {-1, -1};
  };
  for (int i = 0; i < n; ++i) {
    auto [a, b] = f(x - arr[i].first, i + 1);
    if (a != -1) {
      cout << arr[i].second << ' ' << a << ' ' << b << '\n';
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << '\n';
}
