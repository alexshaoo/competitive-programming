#include <bits/stdc++.h>
using namespace std;

template <typename T, size_t SIZE>
void print(const T (&array)[SIZE]) {
  for (size_t i = 0; i < SIZE; i++) std::cout << array[i] << " ";
}

template <class ForwardIter>
void print(ForwardIter begin, ForwardIter end) {
  for (; begin != end; ++begin) cout << *begin << " ";
  cout << '\n';
}

#define ll long long

const int MXN = 1e5;
const int MOD = 1e9 + 7;

ll p(int x) {
  ll res = 1;
  for (int i = 0; i < x; i++) res *= 10;
  return res;
}

void solve(ll t) {
  int len = 1;
  while (9 * p(len - 1) * len < t) {
    t -= 9 * p(len - 1) * len;
    len++;
  }

  string s = to_string(p(len - 1) + t / len);
  cout << s[t % len] - '0' << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  ll t;
  cin >> n;
  while (n--) {
    cin >> t;
    solve(t - 1);
  }
}
