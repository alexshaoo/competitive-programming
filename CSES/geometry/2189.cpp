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

int t;
ll x1, y1p, x2, y2p, x3, y3p;
int ans = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> x1 >> y1p >> x2 >> y2p >> x3 >> y3p;
    ll cp = (x2 - x1) * (y3p - y1p) - (y2p - y1p) * (x3 - x1);
    if (cp == 0) {
      cout << "TOUCH" << '\n';
    } else if (cp > 0) {
      cout << "LEFT" << '\n';
    } else {
      cout << "RIGHT" << '\n';
    }
  }
}
