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
  setIO("shuffle");
  ios_base::sync_with_stdio(0);
  cin >> n;
  int a[n], id[n], ne[n] = {0};
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> id[i];
  for (int j = 0; j < 3; ++j) {
    for (int i = 0; i < n; ++i) ne[i] = id[a[i] - 1];
    for (int i = 0; i < n; ++i) id[i] = ne[i];
  }

  for (int idd : id) cout << idd << '\n';
}
