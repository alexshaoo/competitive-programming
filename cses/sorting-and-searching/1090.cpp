#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(all(arr));
  int l = 0, r = n - 1;
  int c = 0;
  while (l < r) {
    if (arr[l] + arr[r] <= x) {
      ++l;
    }
    --r;
    ++c;
  }
  if (l == r)
    cout << c + 1 << '\n';
  else
    cout << c << '\n';
}
