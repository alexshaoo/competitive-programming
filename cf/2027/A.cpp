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
#define all(x) (x).begin(), (x).end()

const int MAXN = 1e2 + 5;
const int MOD = 1e9 + 7;

void solve() {
  bool arr[MAXN][MAXN] = {false};
  int n;
  cin >> n;
  while (n--) {
    int w, h;
    cin >> w >> h;
    for (int i = 1; i <= h; ++i) {
      for (int j = 1; j <= w; ++j) {
        arr[i][j] = true;
      }
    }
  }
  int ans = 0;
  vector<int> dirs = {0, 1, 0, -1, 0};
  for (int i = 1; i < MAXN; ++i) {
    for (int j = 1; j < MAXN; ++j) {
      if (arr[i][j]) {
        for (int dir = 0; dir < 4; ++dir) {
          int x = j + dirs[dir], y = i + dirs[dir + 1];
          if (!arr[y][x]) {
            ++ans;
          }
        }
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
