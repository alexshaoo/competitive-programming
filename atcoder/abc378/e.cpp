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

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, M;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  // int base = 2, exp = N - 1;
  // int res = 1;
  // while (exp > 0) {
  // cout << exp << '\n';
  // if (exp & 1) {
  // cout << "ADD ON STUFF: " << base << '\n';
  // res = (res * base) % M;
  // }
  // base = (base * base) % M;
  // exp >>= 1;
  // }
  // cout << res << '\n';
  vector<int> pre = {0};
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    pre.push_back((pre[i] + a) % M);
  }
  ll ans = 0;
  unordered_map<int, int> seen;
  seen[0] = 1;
  for (int i = 1; i <= N; ++i) {
    for (auto& [num, freq] : seen) {
      ans += freq * ((pre[i] - num + M) % M);
    }
    seen[pre[i]]++;
  }
  cout << ans << '\n';
}
