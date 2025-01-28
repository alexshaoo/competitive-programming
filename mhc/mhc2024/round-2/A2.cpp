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
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

vector<ull> mountains;

int solve() {
  ll a, b, m;
  cin >> a >> b >> m;
  int ans = 0;
  ll l = *lower_bound(all(mountains), a);
  while (l <= b) {
    if (l % m == 0) {
      ++ans;
    }
    l = *upper_bound(all(mountains), l);
  }
  return ans;
}

ull rev(ull num) {
  ull ans = 0;
  while (num > 0) {
    ans = 10 * ans + num % 10;
    num /= 10;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  vector<vector<ull>> uphill(10), downhill(10);
  function<void(int, int, ull)> f = [&](int n, int i, ull num) {
    ull last = max(1ULL, num % 10);
    if (n == i) {
      for (int peak = last; peak <= 9; ++peak) {
        ull possible = 10 * num + peak;
        uphill[n].push_back(possible);
        downhill[n].push_back(rev(possible));
      }
      return;
    }
    for (int digit = last; digit <= 8; ++digit) {
      f(n, i + 1, 10 * num + digit);
    }
  };
  for (int i = 0; i < 9; ++i) {  // length of uphill
    f(i, 0, 0);
  }
  mountains.push_back(1);
  for (int len = 0; len < 9; ++len) {  // length
    for (auto up : uphill[len]) {
      for (auto down : downhill[len]) {
        for (int peak = max(up % 10, down % 10); peak <= 9; ++peak) {
          int num = 10 * up + peak;
          num *= pow(10, to_string(down).length());
          num += down;
          mountains.push_back(num);
        }
      }
    }
  }
  for (int i = 0; i < 100; ++i) {
    cout << mountains[i] << ' ';
  }
  cout << '\n';
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": " << solve() << '\n';
  }
}
