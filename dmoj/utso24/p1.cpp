#include <bits/stdc++.h>

using namespace std;

long long solve(long long N, long long K) {
  if (K >= N) {
    return 2 * N;
  }
  return 2 * N + solve(N - K, K);
}

int main() {
  long long N, K;
  cin >> N >> K;
  cout << solve(N, K) << '\n';
}