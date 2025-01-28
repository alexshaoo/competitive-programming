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

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

#define ll long long

const int MXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int bi, bf, si, sf, gi, gf, pi, pf;
int ans = 0;

int main() {
  setIO("promote");
  ios_base::sync_with_stdio(0);
  cin >> bi >> bf;
  cin >> si >> sf;
  cin >> gi >> gf;
  cin >> pi >> pf;
  cout << sf + gf + pf - si - gi - pi << '\n'
       << gf + pf - gi - pi << '\n'
       << pf - pi << '\n';
}
