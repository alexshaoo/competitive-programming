#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MXN = 1e5;

void solve(ll n) {
  ll sm = n * (n + 1) / 2;
  if (sm % 2 == 1) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
  // 0 or 3 mod 4 now
  vector<int> res1, res2;
  if (n % 4 == 0) {
    for (int i = 0; i < n / 4; ++i) {
      res1.push_back(4 * i + 1);
      res1.push_back(4 * i + 4);
      res2.push_back(4 * i + 2);
      res2.push_back(4 * i + 3);
    }
  } else {
    res1.push_back(1);
    res1.push_back(2);
    res2.push_back(3);

    for (int i = 0; i < n / 4; ++i) {
      res1.push_back(4 * i + 4);
      res1.push_back(4 * i + 7);
      res2.push_back(4 * i + 5);
      res2.push_back(4 * i + 6);
    }
  }
  cout << res1.size() << '\n';
  for (const auto& num : res1) {
    cout << num << " ";
  }
  cout << '\n' << res2.size() << '\n';
  for (const auto& num : res2) {
    cout << num << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  solve(n);
}
