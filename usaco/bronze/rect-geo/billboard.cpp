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
#define all(x) (x).begin(), (x).end()

const int MXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int ans = 0;

int main() {
  setIO("billboard");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<int> first(4), second(4), truck(4);
  for (int i = 0; i < 4; ++i) {
    cin >> first[i];
  }
  for (int i = 0; i < 4; ++i) {
    cin >> second[i];
  }
  for (int i = 0; i < 4; ++i) {
    cin >> truck[i];
  }
  ans += (first[2]-first[0])*(first[3]-first[1]);
  ans += (second[2]-second[0])*(second[3]-second[1]);
  pair<int, int> bl, tr;
  bl = {max(first[0], truck[0]), max(first[1], truck[1])};
  tr = {min(first[2], truck[2]), min(first[3], truck[3])};
  if (tr.first > bl.first && tr.second > bl.second) {
    ans -= (tr.first-bl.first)*(tr.second-bl.second);
  }
  bl = {max(second[0], truck[0]), max(second[1], truck[1])};
  tr = {min(second[2], truck[2]), min(second[3], truck[3])};
  if (tr.first > bl.first && tr.second > bl.second) {
    ans -= (tr.first-bl.first)*(tr.second-bl.second);
  }
  cout << ans << '\n';
}
