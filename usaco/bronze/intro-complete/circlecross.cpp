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

int n, ans = 0;

int main() {
  // setIO("circlecross");
  ios_base::sync_with_stdio(0);
  string s;
  cin >> s;
  unordered_map<char, pair<int, int>> mp;
  for (char c = 'A'; c <= 'Z'; ++c) {
    auto l = s.find(c);
    auto r = s.find(c, l+1);
    mp[c] = {l, r};
  }
  for (char c = 'A'; c <= 'Z'; ++c) {
    int cl = mp[c].first, cr = mp[c].second;
    for (char d = 'A'; d <= 'Z'; ++d) {
      int dl = mp[d].first, dr = mp[d].second;
      if (cl < dl && dl < cr && cr < dr) ++ans;
    }
  }
  cout << ans << '\n';
}
