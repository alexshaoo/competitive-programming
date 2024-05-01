#include <bits/stdc++.h>
using namespace std;

template <typename T, size_t SIZE>
void print(const T (&array)[SIZE]) {
  for (size_t i = 0; i < SIZE; i++) std::cout << array[i] << " ";
}

template <class ForwardIter>
void print(ForwardIter begin, ForwardIter end) {
  for (; begin != end; ++begin) cout << *begin << " ";
  cout << endl;
}

#define ll long long

const int MXN = 1e5;
const int MOD = 1e9 + 7;

int ans = 0;

int main() {
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> ds(n);
  for (int i = 0; i < n; ++i) {
    cin >> ds[i];
  }
  vector<int> s(m);
  for (int i = 0; i < m; ++i) {
    cin >> s[i];
  }
  sort(ds.begin(), ds.end());
  sort(s.begin(), s.end());
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (abs(ds[i] - s[j]) <= k) {
      ++i;
      ++j;
      ++ans;
    } else {
      if (ds[i] > s[j])
        ++j;
      else
        ++i;
    }
  }
  cout << ans << '\n';
}
