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

int n;

int main() {
  setIO("blocks");
  ios_base::sync_with_stdio(0);
  unordered_map<char, int> s;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string a, b;
    cin >> a >> b;
    int an = a.length(), bn = b.length();
    unordered_map<char, int> am, bm;
    for (int i = 0; i < an; ++i) {
      am[a[i]]++;
    }
    for (int i = 0; i < bn; ++i) {
      bm[b[i]]++;
    }
    for (char c = 'a'; c <= 'z'; ++c) {
      s[c] += max(am[c], bm[c]);
    }
  }
  for (char c = 'a'; c <= 'z'; ++c) {
    cout << s[c] << '\n';
  }
  return 0;
}
