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
#define all(x) (x).begin(), (x).end()

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

void solve() {}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, t;
  cin >> n >> t;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  int l = 0, ans = 0;
  ll time = 0;
  for (int r = 0; r < n; ++r) {
    time += arr[r];
    while (time > t) {
      time -= arr[l++];
    }
    ans = max(ans, r - l + 1);
  }
  cout << ans << '\n';
}
