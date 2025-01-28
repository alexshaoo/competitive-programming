#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int hats[n];
  for (int i = 0; i < n; ++i) {
    cin >> hats[i];
  }
  int c = 0;
  for (int i = 0; i < n / 2; ++i) {
    if (hats[i] == hats[i + n / 2]) ++c;
  }
  cout << 2 * c << '\n';
}