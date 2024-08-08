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

int main() {
  setIO("shell");
  ios_base::sync_with_stdio(0);
  cin >> n;
  vector<int> arr(3), c(3);
  iota(arr.begin(), arr.end(), 1);
  int a, b, g;
  while (n--) {
    cin >> a >> b >> g;
    --a, --b, --g;
    // do a swap
    swap(arr[a], arr[b]);
    c[arr[g]]++;
  }
  ans = max(c[0], max(c[1], c[2]));
  cout << ans << '\n';
}
