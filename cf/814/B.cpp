#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

bool isPermutation(const vector<int>& v, int n) {
  vector<int> ref(n);
  iota(all(ref), 1);
  return is_permutation(all(v), ref.begin());
}

int missing(const vector<int>& v, int n) {
  unordered_set<int> s;
  for (int i = 1; i <= n; ++i) s.insert(i);
  for (int a : v) s.erase(a);
  return *s.begin();
}

pair<int, int> dup(const vector<int>& v, int n) {
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (v[i] == v[j]) return make_pair(i, j);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n, 0), b(n, 0);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];

  vector<int> a1(all(a)), a2(all(a));
  pair<int, int> adup = dup(a, n);
  int amissing = missing(a, n);
  a1[adup.first] = amissing;
  a2[adup.second] = amissing;

  vector<int> b1(all(b)), b2(all(b));
  pair<int, int> bdup = dup(b, n);
  int bmissing = missing(b, n);
  b1[bdup.first] = bmissing;
  b2[bdup.second] = bmissing;

  if (a1 == b1 || a1 == b2) {
    for (int num : a1) cout << num << ' ';
  } else {
    for (int num : a2) cout << num << ' ';
  }
  return 0;
}
