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

int n, k;
string s;

int main() {
  setIO("word");
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  vector<string> words(n);
  for (int i = 0; i < n; ++i) {
    cin >> words[i];
  }
  int i = 0, sz = 0;
  while (i < n) {
    if (sz + (int)words[i].size() > k) {
      s.pop_back();
      cout << s << '\n';
      s = "";
      sz = 0;
    } else {
      s += words[i] + ' ';
      sz += words[i].size();
      ++i;
    }
  }
  while (s.back() == ' ') s.pop_back();
  cout << s;
}
