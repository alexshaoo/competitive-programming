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

#define ull unsigned long long
#define ll long long
#define all(x) (x).begin(), (x).end()

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> sm(n);
  sm[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    sm[i] = sm[i + 1] + (n - i) * a[i];
  }
  vector<int> lb(n), rb(n);
  int le = 1, ri = n;
  for (int i = 0; i < n; ++i) {
    lb[i] = le;
    rb[i] = ri;
    le = ri + 1;
    ri += (n - i - 1);
  }
  // for (int i = 0; i < n; ++i) {
  // cout << bounds[i].first << ' ' << bounds[i].second << '\n';
  // }
  int q;
  cin >> q;
  while (q--) {
    ull l, r;
    cin >> l >> r;
    int li = upper_bound(all(lb), l) - lb.begin() - 1;
    int ri = upper_bound(all(rb), r) - rb.begin() - 1;
    cout << li << ' ' << ri << '\n';
    ull ans = 0;
    for (int i = li; i <= ri; ++i) {
      ans += sm[i];
    }
    for (int i = l - lb[li]; i > 0; --i) {
      ans -= a[li++] * i;
    }
    
    for (int i = r - rb[ri]; i > 0; --i) {
      ans += a[ri++] * i;
    }
    cout << ans << '\n';
  }
}
