#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (k > 1) {
    cout << "Yes" << '\n';
    return 0;
  }
  vector<int> a(n, 0);
  int b;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cin >> b;
  for (int& aa : a) {
    if (aa == 0) {
      aa = b;
      break;
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] > a[i + 1]) {
      cout << "Yes" << '\n';
      return 0;
    }
  }
  cout << "No" << '\n';
  return 0;
}
