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

const int MXN = 5e3 + 5;
const int MXK = 5e5 + 5;
const int MOD = 1e9 + 7;

int n, k, i = 1, dp[MXN];
string ans;

struct node {
  int fail, ch[26] = {};
  vector<int> lens;
  string s = "";
} T[MXK];

int main() {
  ios_base::sync_with_stdio(0);
  string s;
  cin >> s;
  cin >> n;
  for (int i = 0; i <) cout << ans << '\n';
}
