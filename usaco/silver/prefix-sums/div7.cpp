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

const int MXN = 5e5 + 5;
const int MOD = 1e9 + 7;

int n, ans = 0;

int main() {
  setIO("div7");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  vector<int> ps(n);
  ps[0] = arr[0]%7;
  for (int i = 1; i < n; ++i) {
    ps[i] = (ps[i-1] + arr[i])%7;
  }
  
  for (int i = 0; i < 7; ++i) {
    int mn = MXN, mx = -1;
    for (int j = 0; j < n; ++j) {
      if (ps[j] == i) {
        mn = min(mn, j);
        mx = max(mx, j);
      }
    }
    ans = max(ans, mx-mn);
  }
  cout << ans << '\n';
}
