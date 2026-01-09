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

string s[8];
bool b[15];

void solve() {
  int p[8], ans = 0;
  iota(p, p + 8, 0);
  do {
    bool ok = 1;
    for (int i = 0; i < 8; ++i) {
      ok &= s[i][p[i]] == '.';
    }
    memset(b, 0, 15);
    for (int i = 0; i < 8; ++i) {
      if (b[i + p[i]]) ok = 0;
      b[i + p[i]] = 1;
    }
    memset(b, 0, 15);
    for (int i = 0; i < 8; ++i) {
      if (b[i + 7 - p[i]]) ok = 0;
      b[i + 7 - p[i]] = 1;
    }
    ans += ok;
  } while (next_permutation(p, p + 8));
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 8; ++i) cin >> s[i];
  solve();
}
