#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  ll cnt = 1;
  unordered_map<int, int> freq;

  while (n--) {
    int x;
    cin >> x;
    freq[x]++;
  }

  for (auto &[k, v] : freq) {
    cnt = (cnt * (v + 1)) % MOD;
  }

  // don't count empty subseq
  cnt = (MOD + cnt - 1) % MOD;

  cout << cnt << '\n';
}
