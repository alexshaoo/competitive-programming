#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<array<int, 3>> ranges(n); // (start, end, index)
  for (int i = 0; i < n; ++i) {
    cin >> ranges[i][0] >> ranges[i][1];
    ranges[i][2] = i;
  }
  vector<int> contains(n), contained(n);
  sort(all(ranges), [&](array<int, 3> &a, array<int, 3> &b) {
    if (a[0] == b[0])
      return a[1] > b[1];
    return a[0] < b[0];
  });
  // contains
  int min_end = 2e9;
  for (int i = n - 1; i >= 0; --i) {
    if (ranges[i][1] >= min_end) {
      contains[ranges[i][2]] = 1;
    }
    min_end = min(min_end, ranges[i][1]);
  }
  // contained
  int max_end = 0;
  for (int i = 0; i < n; ++i) {
    if (ranges[i][1] <= max_end) {
      contained[ranges[i][2]] = 1;
    }
    max_end = max(max_end, ranges[i][1]);
  }
  for (int x : contains)
    cout << x << ' ';
  cout << '\n';
  for (int x : contained)
    cout << x << ' ';
  cout << '\n';
}
