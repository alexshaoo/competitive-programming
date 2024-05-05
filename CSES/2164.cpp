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

int solve(int n, int k) {
  if (n <= 1) return n;
  int num = (n & 1) ? (n + 1) / 2 : n / 2;
  int shift = (n & 1) ? 1 : -1;
  if (k <= num) {
    return (2 * k - 1) % n + 1;
  }
  return 2 * solve(n >> 1, k - num) + shift;
}

int main() {
  ios_base::sync_with_stdio(0);
  int q;
  cin >> q;
  int n, k;
  while (q--) {
    cin >> n >> k;
    cout << solve(n, k) << '\n';
  }
}
