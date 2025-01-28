#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> happiness(N);
  for (int i = 0; i < N; ++i) {
    cin >> happiness[i];
  }
  sort(happiness.begin(), happiness.end());
  int pi =
      upper_bound(happiness.begin(), happiness.end(), 0) - happiness.begin();
  int nf = lower_bound(happiness.begin(), happiness.end(), 0) -
           happiness.begin() - 1;

  cout << pi << ' ' << nf << '\n';
  int ni = 0, pf = N - 1;
  long long score = 0;
  int p = pf;
  for (; p > nf; p--) {
    if (K <= 0) break;
    K--;
    score += happiness[p];
  }
  int n = ni;
  for (; n < pi; n++) {
    if (K <= 1) break;
    K -= 2;
    score += -1 * happiness[n];
  }

  cout << n << ' ' << p << '\n';
  cout << score << '\n';
  while (K > 0 && n <= nf && p <= pf) {
    int delta = -1 * happiness[n] - happiness[p];
    if (delta <= 0) break;
    score += delta;
    K--;
    p += 2;
    n++;
  }
  for (int num : happiness) {
    cout << num << ' ';
  }
  cout << '\n';
  cout << n << ' ' << p << '\n';
  cout << score << '\n';
  while (n <= nf && p < pf) {
    int delta = -1 * happiness[n] - happiness[p] - happiness[p + 1];
    if (delta <= 0) break;
    score += delta;
    p += 2;
    n++;
  }
  cout << score << '\n';
}