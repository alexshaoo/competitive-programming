#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i)
    cin >> grid[i];
  string ans;
  ans += grid[0][0];
  vector<pair<int, int>> valid;
  valid.push_back({0, 0});
  vector<vector<bool>> seen(n, vector<bool>(n, false));
  for (int i = 0; i < 2 * (n - 1); ++i) {
    char minChar = 'Z';
    vector<pair<int, int>> positions;
    for (const auto &[r, c] : valid) {
      if (r + 1 < n && !seen[r + 1][c]) {
        seen[r + 1][c] = true;
        char currChar = grid[r + 1][c];
        if (currChar < minChar) {
          positions.clear();
          minChar = currChar;
        }
        if (currChar == minChar) {
          positions.push_back({r + 1, c});
        }
      }
      if (c + 1 < n && !seen[r][c + 1]) {
        seen[r][c + 1] = true;
        char currChar = grid[r][c + 1];
        if (currChar < minChar) {
          positions.clear();
          minChar = currChar;
        }
        if (currChar == minChar) {
          positions.push_back({r, c + 1});
        }
      }
    }
    ans += minChar;
    swap(valid, positions);
  }
  cout << ans << '\n';
}
