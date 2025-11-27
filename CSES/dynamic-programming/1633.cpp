#include <bits/stdc++.h>
using namespace std;

template <typename T, size_t SIZE>
void print(const T (&array)[SIZE]) {
  for (size_t i = 0; i < SIZE; i++) std::cout << array[i] << " ";
}

template <class ForwardIter>
void print(ForwardIter begin, ForwardIter end) {
  for (; begin != end; ++begin) cout << *begin << " ";
  cout << endl;
}

#define ll long long

const int MXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int ans = 0;
int dp[MXN];

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  dp[0] = 1;
  for (int i = 0; i <= n; ++i) {
    for (int j = max(0, i - 6); j < i; ++j) {
      dp[i] = (dp[i] + dp[j]) % MOD;
    }
  }
  cout << dp[n] << '\n';
}
