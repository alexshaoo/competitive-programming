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
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  if (n == 5) {
    cout << "5\n2 1 3 4 5\n";
    return;
  }
  if (n == 6) {
    cout << "7\n1 2 4 6 5 3\n";
    return;
  }
  if (n == 7) {
    cout << "15\n2 4 5 1 3 6 7\n";
    return;
  }
  vector<int> seq = {1, 2, 6, 5, 3, 4, 7, 8};
  if (n % 2 == 0) {
    cout << (1 << static_cast<int>(log2(n)) + 1) - 1;
  } else {
    cout << n;
  }
  cout << '\n';
  for (int i = 0; i < 8; i += 2) {
    int a = seq[i];
    int b = seq[i + 1];

    for (int j = 0; a + j <= n && b + j <= n; j += 8) {
      cout << a + j << ", " << b + j << ", ";
    }
  }
  if (n % 2 == 1) {
    cout << n;
  }
  cout << '\n';
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
