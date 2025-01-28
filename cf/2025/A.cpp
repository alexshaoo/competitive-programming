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

#define ll long long
#define all(x) (x).begin(), (x).end()

const int MXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    string s, t;
    cin >> s;
    cin >> t;
    int pre = 0;
    for (int i = 0; i < max(s.length(), t.length()); ++i, ++pre) {
      if (s[i] != t[i]) {
        break;
      }
    }
    cout << s.length() + t.length() - pre + (pre != 0) << '\n';
  }
}
