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

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int main() {
  setIO("diamond");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(all(arr));
  unordered_map<int, int> inc;
  for (int i = 0; i < n; ++i) {  // also do this using two pointers
    int ind = upper_bound(all(arr), arr[i] + k) - arr.begin();
    inc[arr[i]] = max(inc[arr[i]], ind - i);
  }
  unordered_map<int, int> ss;
  for (int i = n - 2; i >= 0; --i) {
    ss[arr[i]] = max(ss[arr[i + 1]], inc[arr[i]]);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, inc[arr[i]] + ss[*upper_bound(all(arr), arr[i] + k)]);
  }
  cout << ans << '\n';
}
