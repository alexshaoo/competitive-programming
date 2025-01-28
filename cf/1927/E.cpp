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

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  int rows = n / k;
  int extras = n % k;
  vector<vector<int>> container(rows + 1, vector<int>(k, 0));
  int num = 1;
  for (int c = 0; c < k; ++c) {
    for (int r = 0; r < rows + (c < extras); ++r) {
      container[r][c] = num++;
    }
  }
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < k; ++c) {
      cout << container[r][c] << ' ';
    }
  }
  for (int c = 0; c < extras; ++c) {
    cout << container[rows][c] << ' ';
  }
  cout << '\n';
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
