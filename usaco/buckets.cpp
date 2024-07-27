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

char graph[10][10];
int ans = 0;
int lx, ly, rx, ry, bx, by;

int main() {
  setIO("buckets");
  ios_base::sync_with_stdio(0);
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      cin >> graph[i][j];
      if (graph[i][j] == 'L') {
        lx = i;
        ly = j;
      } else if (graph[i][j] == 'R') {
        rx = i;
        ry = j;
      } else if (graph[i][j] == 'B') {
        bx = i;
        by = j;
      }
    }
  }
  auto f = [](int xi, int xf, int yi, int yf) {
    return abs(xi - xf) + abs(yi - yf);
  };
  int bl = f(lx, bx, ly, by);
  int br = f(rx, bx, ry, by);
  int rl = f(rx, lx, ry, ly);
  ans = abs(lx - bx) + abs(ly - by) - 1;
  if (bl == br + rl && ((lx == rx && rx == bx) || (ly == ry && ry == by)))
    ans += 2;
  cout << ans << '\n';
}
