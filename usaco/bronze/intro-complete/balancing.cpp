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

int n, b, ans = INT_MAX;

int main() {
  setIO("balancing");
  ios_base::sync_with_stdio(0);
  cin >> n >> b;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
  for (int i = 0; i < n; ++i) {
    int xl = x[i]+1;
    for (int j = 0; j < n; ++j) {
      q1 = 0, q2 = 0, q3 = 0, q4 = 0;
      int yl = y[j]+1;
      for (int p = 0; p < n; ++p) {
        int xx = x[p], yy = y[p];
        if (xx < xl) {
          if (yy < yl) ++q3;
          else ++q2;
        } else {
          if (yy < yl) ++q4;
          else ++q1;
        }
      }
      ans = min(ans, max(q1, max(q2, max(q3, q4))));
    }
  }
  cout << ans << '\n';
}
