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

const int MXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n;
int ans = 0;
int b = 0;

int main() {
  setIO("blist");
  ios_base::sync_with_stdio(0);
  cin >> n;
  vector<pair<int, int>> s(n), t(n);
  for (int i = 0; i < n; ++i) {
    int ss, tt, b;
    cin >> ss >> tt >> b;
    s[i] = {ss, b};
    t[i] = {tt, b};
  }
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  int curr = 0;
  int si = 0, ti = 0;
  for (int i = 1; i <= 1000; ++i) {
    if (si < n && s[si].first == i) {
      curr += s[si++].second;
    }
    if (ti < n && t[ti].first == i) {
      curr -= t[ti++].second;
    }
    ans = max(ans, curr);
  }
  cout << ans << '\n';
}
