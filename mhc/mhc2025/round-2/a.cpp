#include <bits/stdc++.h>
using namespace std;

template <typename T, size_t SIZE> void print(const T (&array)[SIZE]) {
  for (size_t i = 0; i < SIZE; i++)
    cout << array[i] << " ";
  cout << '\n';
}

template <class ForwardIter> void print(ForwardIter begin, ForwardIter end) {
  for (; begin != end; ++begin)
    cout << *begin << " ";
  cout << '\n';
}

#define ll long long
#define all(x) (x).begin(), (x).end()

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

void test_case() {
  int n, m;
  cin >> n >> m;
  bool b = false;
  if (m == 1) {
    b = (n >= 2 && n % 2 == 0);
  } else {
    if (n >= m) {
      if (n <= 2 * m - 2)
        b = true;
      else if (n >= 2 * m && n % 2 == 0)
        b = true;
    }
  }
  cout << (b ? "YES" : "NO") << '\n';
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
