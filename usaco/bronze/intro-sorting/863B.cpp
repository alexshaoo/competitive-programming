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

const int MXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, ans = INT_MAX;

int main() {
  cin >> n;
  vector<int> weights(2*n);
  for (int i = 0; i < 2*n; ++i) cin >> weights[i];
  sort(all(weights));
  for (int i = 0; i < 2*n-1; ++i) {
    for (int j = i+1; j < 2*n; ++j) {
      vector<int> v;
      for (int k = 0; k < weights.size(); ++k) {
        if (k != i && k != j) v.push_back(weights[k]);
      }
      int c = 0;
      for (int i = 0; i < v.size()-1; i += 2) {
        c += abs(v[i]-v[i+1]);
      }
      ans = min(ans, c);
    }
  }
  cout << ans << '\n';
}
