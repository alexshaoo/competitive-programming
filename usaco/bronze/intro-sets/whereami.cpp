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

int n, ans = 0;

int main() {
  setIO("whereami");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  string s;
  cin >> s;
  int len = 1;
  while (len < n) {
    set<string> uniq;
    bool doable = true;
    for (int i = 0; i <= n-len; ++i) {
      string tmp = s.substr(i, len);
      if (uniq.count(tmp) > 0) {
        doable = false;
        break;
      }
      uniq.insert(tmp);
    }
    if (doable) {
      break;
    }
    ++len;
  }
  cout << len << '\n';
}
