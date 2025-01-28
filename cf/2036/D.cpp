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

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, m;

bool eq(string& s, int i) {
  return s[i] == '1' && s[i + 1] == '5' && s[i + 2] == '4' && s[i + 3] == '3';
}

int f(int i, vector<string>& carpet) {
  string path = "";
  int r = i, c = i;
  while (c < m - i - 1) {
    path += carpet[r][c];
    ++c;
  }
  while (r < n - i - 1) {
    path += carpet[r][c];
    ++r;
  }
  while (c > i) {
    path += carpet[r][c];
    --c;
  }
  while (r > i) {
    path += carpet[r][c];
    --r;
  }
  path += path.substr(0, 3);
  int ans = 0;
  for (int i = 0; i < sz(path); ++i) {
    ans += eq(path, i);
  }
  return ans;
}

void solve() {
  cin >> n >> m;
  vector<string> carpet(n);
  for (int i = 0; i < n; ++i) {
    cin >> carpet[i];
  }
  int ans = 0;
  for (int i = 0; i < min(n / 2, m / 2); ++i) {
    ans += f(i, carpet);
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
