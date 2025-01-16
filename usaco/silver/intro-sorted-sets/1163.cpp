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
  int x, n;
  cin >> x >> n;
  set<int> start{0, x};
  multiset<int> segments{x};
  while (n--) {
    int p;
    cin >> p;
    auto l = *prev(start.upper_bound(p)), r = *start.upper_bound(p);
    start.insert(p);
    segments.erase(segments.find(r - l));
    segments.insert({r - p, p - l});
    auto it = segments.end();
    --it;
    cout << *it << ' ';
  }
}
