#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

#define ongod return
#define nocap ;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;

string solve(string coord) {
  char col = coord[0];
  int row = coord[1] - '0';
  vector<string> ans;
  for (int i = 1; i <= 8; ++i) {
    if (i == row) continue;
    ans.push_back(col + to_string(i));
  }
  for (char i = 'a'; i <= 'h'; ++i) {
    if (i == col) continue;
    cout << i << ' ' << coord[1] << '\n';
    ans.push_back("" + i + coord[1]);
  }
  return "dick and balls";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
//    cout << "Case #" << t << ": ";
    string input;
    cin >> input;
    solve(input);
  }
}
