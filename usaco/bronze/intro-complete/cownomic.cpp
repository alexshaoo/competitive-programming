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

int n, m, ans = 0;

int main() {
  setIO("cownomics");
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  string spotty[n], plain[n];
  for (int i = 0; i < n; ++i) cin >> spotty[i];
  for (int i = 0; i < n; ++i) cin >> plain[i];
  for (int i = 0; i < m-2; ++i) {
    for (int j = i+1; j < m-1; ++j) {
      for (int k = j+1; k < m; ++k) {
        set<string> s;
        for (int ind = 0; ind < n; ++ind) {
          string curr = {spotty[ind][i], spotty[ind][j], spotty[ind][k]};
          s.insert(curr);
        }
        bool b = true;
        for (int ind = 0; ind < n; ++ind) {
          string curr = {plain[ind][i], plain[ind][j], plain[ind][k]};
          if (s.find(curr) != s.end()) {
            b = false;
            break;
          }
        }
        ans += b;
      }
    }
  }
  cout << ans << '\n';
}
