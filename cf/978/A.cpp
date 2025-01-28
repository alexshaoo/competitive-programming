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

const int MXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, r;
    cin >> n >> r;
    vector<int> arr(n);
    int together = 0;
    int alone = 0;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      together += (arr[i] / 2);
      alone += (arr[i] % 2);
    }
    int ans = 2 * together;
    int rem = 2 * (r - together);
    ans += min(alone, rem - alone);
    cout << ans << '\n';
  }
}
