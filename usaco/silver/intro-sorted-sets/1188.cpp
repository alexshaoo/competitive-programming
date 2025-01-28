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

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

// basically taken directly from
// https://usaco.guide/silver/intro-sorted-sets?lang=cpp, had such a hard time
// wrapping my head around this
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string bs;
  cin >> bs;
  int n = sz(bs);
  int m;
  cin >> m;
  set<int> start = {0, n};
  for (int i = 0; i < n - 1; ++i) {
    if (bs[i] != bs[i + 1]) {
      start.insert(i + 1);
    }
  }
  multiset<int> lengths;
  for (auto it = next(start.begin()); it != start.end(); ++it) {
    lengths.insert(*it - *prev(it));
  }
  auto f = [&](int x) -> void {
    if (x == 0 || x == n) {
      return;
    };
    if (start.find(x) != start.end()) {
      auto pos = start.find(x);
      auto l = *prev(pos), r = *next(pos);
      lengths.erase(lengths.find(x - l));
      lengths.erase(lengths.find(r - x));
      lengths.insert(r - l);
      start.erase(x);
    } else {
      start.insert(x);
      auto pos = start.find(x);
      auto l = *prev(pos), r = *next(pos);
      lengths.erase(lengths.find(r - l));
      lengths.insert(x - l);
      lengths.insert(r - x);
    }
  };
  while (m--) {
    int x;
    cin >> x;
    --x;
    f(x);
    f(x + 1);
    cout << *lengths.rbegin() << ' ';
  }
}
