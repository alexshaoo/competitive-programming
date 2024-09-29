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

const int MXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, ans = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> n >> q;
  vector<vector<int>> forest(n+1, vector<int>(n+1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      char c;
      cin >> c;
      int add = (int)(c == '*');
      forest[i][j] = add + forest[i-1][j] + forest[i][j-1] - forest[i-1][j-1];
    }
  }
  while (q--) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    --y1; --x1;
    cout << forest[y1][x1] - forest[y2][x1] - forest[y1][x2] + forest[y2][x2] << '\n';
  }
}
