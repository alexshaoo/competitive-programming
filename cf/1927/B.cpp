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

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  unordered_map<int, unordered_set<int>> potential;
  for (int i = 0; i < 26; ++i) {
    potential[0].insert(i);
  }
  string s;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    auto it = potential[a].begin();
    s += ('a' + *it);
    potential[a + 1].insert(*it);
    potential[a].erase(it);
  }
  cout << s << '\n';
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
