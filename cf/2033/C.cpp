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

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int f(const vector<int>& arr) {
  int disturbance = 0;
  for (int i = 0; i < arr.size() - 1; ++i) {
    if (arr[i] == arr[i + 1]) {
      disturbance++;
    }
  }
  return disturbance;
}

int g(int i, int n, const vector<int>& arr) {
  int c = 0;
  if (i > 0) {
    c += (arr[i - 1] == arr[i]);
    c += (arr[n - i] == arr[n - i - 1]);
  }
  if (i < n - 1) {
    c += (arr[i] == arr[i + 1]);
    c += (arr[n - i - 1] == arr[n - i - 2]);
  }
  return c;
}

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int base_disturbance = f(arr);

  vector<array<int, 2>> dp(n / 2, {0, 0});

  dp[0][0] = base_disturbance;

  swap(arr[0], arr[n - 1]);
  dp[0][1] = f(arr);
  swap(arr[0], arr[n - 1]);

  for (int i = 1; i < n / 2; ++i) {
    dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);

    swap(arr[i], arr[n - i - 1]);
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + g(i, n, arr);
    swap(arr[i], arr[n - i - 1]);
  }
  int result = min(dp[n / 2 - 1][0], dp[n / 2 - 1][1]);
  cout << result << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
