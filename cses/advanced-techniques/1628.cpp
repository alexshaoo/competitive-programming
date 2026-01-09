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

const int MXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int dfs(vector<int> &t, int i) { if (i >= t.size()) }

int main() {
  ios_base::sync_with_stdio(0);
  int n, ans, x;
  vector<int> t;
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }

  cout << ans << '\n';
}
