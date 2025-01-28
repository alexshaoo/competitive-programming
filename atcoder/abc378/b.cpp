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

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  vector<pair<long long, long long>> collected(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> collected[i].first >> collected[i].second;
  }
  ll q;
  cin >> q;
  while (q--) {
    ll t, d;
    cin >> t >> d;
    auto& [q, r] = collected[t];
    ll cycle = (d - r + q - 1) / q;
    cout << q * (cycle) + r << '\n';
  }
}
