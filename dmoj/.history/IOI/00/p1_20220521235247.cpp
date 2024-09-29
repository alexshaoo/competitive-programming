#include <bits/stdc++.h>
#define same(x) (x & 1) ^ 1

using namespace std;

int N, dp[5001][2];
string S;

int main() {
  cin >> N;
  cin >> S;

  // string reversed = S;
  // reverse(reversed.begin(), reversed.end());

  // // compare each letter
  // for (int i = 0; i < N; ++i) {
  //     for (int j = 0; j < N; ++j) {

  //         if (S[i] == reversed[j]) dp[same((i+1)^1)][j+1] + 1;
  //         else dp[same((i+1)^1)][j+1] = max(dp[same((i+1)^1)][j+1], dp[same(i+1)][j]);

  //     }
  // }

  // cout << S.length() - dp[same(N)][N];

  for (int i = 1; 1 < n)
}