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

int n, t, ans = 0;

int main() {
  setIO("tracing");
  ios_base::sync_with_stdio(0); 
  cin.tie(0);
  cin >> n >> t;
  string s;
  cin >> s;
  set<int> pos;
  int minK = t+1, maxK = -1;
  vector<vector<int>> interactions(t, vector<int>(3, 0));
  for (int i = 0; i < t; ++i) {
    cin >> interactions[i][0] >> interactions[i][1] >> interactions[i][2];
  }
  sort(interactions.begin(), interactions.end());
  for (int k = 0; k <= t; ++k) {
    for (int ic = 1; ic <= n; ++ic) {
      vector<int> infectionsPassed(n+1, 0);
      string infected(n+1, '0');
      infected[ic] = '1';
      for (const auto& interaction : interactions) {
        char& c1 = infected[interaction[1]];
        char& c2 = infected[interaction[2]];
        if (c1 == '1' && c2 == '1') {
          infectionsPassed[interaction[1]]++;
          infectionsPassed[interaction[2]]++;
        } else if (infectionsPassed[interaction[1]] < k && c1 == '1' && c2 == '0') {
          c2 = '1';
          infectionsPassed[interaction[1]]++;
        } else if (infectionsPassed[interaction[2]] < k && c2 == '1' && c1 == '0') {
          c1 = '1';
          infectionsPassed[interaction[2]]++;
        }
      }
      if (infected.substr(1) == s) {
        minK = min(minK, k);
        maxK = max(maxK, k);
        pos.insert(ic);
      }
    }
  }
  cout << pos.size() << ' ' << minK << ' ' << (maxK == t ? "Infinity" : to_string(maxK)) << '\n';
}