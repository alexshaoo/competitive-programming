#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;

void solve(string coord) {
  vector<string> ans;
  char row = coord[1];
  char col = coord[0];
  for (int i = 1; i <= 8; ++i) {
    if (i == (row - '0')) continue;
    ans.push_back(coord[0] + to_string(row));
  }
  for (char i = 'a'; i <= 'h'; ++i) {
    if (col == i) continue;
    ans.push_back(to_string(i) + row);
  }
  for (const auto& c : ans) {
    cout << c << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    string coord;
    cin >> coord;
    cout << coord << '\n';
    solve(coord);
  }

  cout << "doned\n";
}
