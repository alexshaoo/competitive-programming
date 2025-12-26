#include <bits/stdc++.h>
using namespace std;

template <typename T, size_t SIZE>
void print(const T (&array)[SIZE]) {
  for (size_t i = 0; i < SIZE; i++) cout << array[i] << " ";
  cout << '\n';
}

template <class ForwardIter> void print(ForwardIter begin, ForwardIter end) {
  for (; begin != end; ++begin) cout << *begin << " ";
  cout << '\n';
}

#define ll long long
#define all(x) (x).begin(), (x).end()

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

void test_case() {
  int ans = -1;
  int n;
  cin >> n;
  vector<pair<int, int>> a(n), b(n);
  unordered_set<int> as, bs;
  int tmp;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    a[i] = {tmp, i+1};
    as.insert(tmp);
  }
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    b[i] = {tmp, i+1};
    bs.insert(tmp);
  }
  for (auto it = bs.begin(); it != bs.end(); ++it) {
      if (as.count(*it) == 0) {
          cout << ans << '\n';
          return;
      }
  }
  vector<pair<int, int>> moves;

  cout << "here" << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    test_case();
  }
  return 0;
}
