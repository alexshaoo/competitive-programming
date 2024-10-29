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
  int n, q;
  cin >> n >> q;
  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  sort(all(arr));
  unordered_set<int> dep;
  for (int i = 0; i < n; ++i) {
    for (int j = min(i, arr[i].second); j < max(i, arr[i].second); ++j) {
      dep.insert(j);
    }
  }
  string swaps;
  cin >> swaps;
  unordered_set<int> r, l, missing = dep;
  for (int i = 0; i < n; ++i) {
    if (swaps[i] == 'R') {
      r.insert(i);
      if (dep.find(i) != dep.end()) {
        missing.erase(i);
      }
    } else {
      l.insert(i);
      if (dep.find(i - 1) != dep.end()) {
        missing.erase(i - 1);
      }
    }
  }
  while (q--) {
    int a;
    cin >> a;
    --a;
    if (swaps[a] == 'R') {
      r.erase(a);
      if (l.find(a + 1) == l.end() && dep.find(a) != dep.end()) {
        missing.insert(a);
      }
      l.insert(a);
      missing.erase(a - 1);
      swaps[a] = 'L';
    } else {
      l.erase(a);
      if (r.find(a - 1) == r.end() && dep.find(a - 1) != dep.end()) {
        missing.insert(a - 1);
      }
      r.insert(a);
      missing.erase(a);
      swaps[a] = 'R';
    }
    if (missing.empty()) {
      cout << "yes" << '\n';
    } else {
      cout << "no" << '\n';
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
