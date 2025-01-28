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

int n;
int ans = 0;

int main() {
  setIO("mixmilk");
  ios_base::sync_with_stdio(0);
  vector<int> c(3), m(3);
  cin >> c[0] >> m[0];
  cin >> c[1] >> m[1];
  cin >> c[2] >> m[2];
  for (int i = 0; i < 100; ++i) {
    int j = (i + 1) % 3;
    int a = min(m[i % 3], c[j] - m[j]);
    m[i % 3] -= a;
    m[j] += a;
  }
  for (int mm : m) cout << mm << '\n';
}
