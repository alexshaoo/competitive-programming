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
using i128  = __int128_t;
#define all(x) (x).begin(), (x).end()

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

void test_case() {
  int n;
  cin >> n;
  vector<ll> A(n);
  for (int i = 0; i < n; ++i) cin >> A[i];
  unordered_map<ll, ll> freq;
  freq[0] = 1;
  ll px = 0;
  for (int i = 0; i < n; ++i) {
    px ^= A[i];
    ++freq[px];
  }
  auto f = [&](ll d) -> i128 {
    if (d < 3) return 0;
    return (d-2)*(d-1)*d/6;
  };
  i128 dup = 0;
  for (const auto& fre : freq) {
    dup += f(fre.second+1);
  }
  i128 tot = n*(n+1)*(n+2)/6;
  cout << (ll)(tot-dup) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    test_case();
  }
  return 0;
}
