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
#define all(x) (x).begin(), (x).end()

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    unordered_map<int, int> freq;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      freq[arr[i]]++;
    }
    sort(all(arr));
    ll ans = 0;
    for (int i = 0; i < k; ++i) {
      ans += freq[i];
    }
    ll window = ans;
    for (int i = k; i <= min(k + arr[n - 1], MAXN); ++i) {
      window = window + freq[i] - freq[i - k];
      ans = max(ans, window);
    }
    cout << ans << '\n';
  }
}
