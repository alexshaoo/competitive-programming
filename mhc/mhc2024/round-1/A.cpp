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

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

#define ll long long
#define all(x) (x).begin(), (x).end()

const int MXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int main() {
  // setIO("");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int N, K;
    cin >> N >> K;
    ll mn = MOD;
    for (int i = 0; i < N; ++i) {
      ll n;
      cin >> n;
      mn = min(mn, n);
    }
    ll ans = max(1, 2 * N - 3) * mn;
    cout << "Case #" << tc << ": " << (ans <= K ? "YES" : "NO") << '\n';
  }
}
