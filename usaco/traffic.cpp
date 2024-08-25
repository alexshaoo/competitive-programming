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
  setIO("traffic");
  ios_base::sync_with_stdio(0);
  cin >> n;
  int x = 0, y = INT_MAX / 2;
  vector<string> q(n);
  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> q[i] >> l[i] >> r[i];
  }
  for (int i = n - 1; i >= 0; --i) {
    if (q[i] == "none") {
      x = max(x, l[i]);
      y = min(y, r[i]);
    } else if (q[i] == "on") {
      x -= r[i];
      y -= l[i];
      x = max(x, 0);
    } else if (q[i] == "off") {
      x += l[i];
      y += r[i];
    }
  }
  cout << x << ' ' << y << '\n';
  x = 0, y = INT_MAX / 2;
  for (int i = 0; i < n; ++i) {
    if (q[i] == "none") {
      x = max(x, l[i]);
      y = min(y, r[i]);
    } else if (q[i] == "on") {
      x += l[i];
      y += r[i];
    } else if (q[i] == "off") {
      x -= r[i];
      y -= l[i];
      x = max(x, 0);
    }
  }
  cout << x << ' ' << y << '\n';
}
