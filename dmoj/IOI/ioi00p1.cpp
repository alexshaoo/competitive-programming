#include <bits/stdc++.h>
#define same(x) (x & 1) ^ 1

using namespace std;

const int MAXN = 5;
int N, dp[MAXN][2];
int temp[MAXN];
string S;

int main() {
  cin >> N;
  cin >> S;

  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (S[i] == S[i+j]) 
        temp[j] = dp[j+1][0];
      else
        temp[j] = min(dp[j][1], dp[j+1][1]) + 1;
    }
  }

  for (int num : temp) 
    cout << num << " ";
}