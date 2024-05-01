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

const int MXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, q;
int ans = 0;
ll arr[MXN];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i + 1];
    arr[i + 1] += arr[i];
  }
  int a, b;
  while (q--) {
    cin >> a >> b;
    cout << arr[b] - arr[a - 1] << '\n';
  }
}
