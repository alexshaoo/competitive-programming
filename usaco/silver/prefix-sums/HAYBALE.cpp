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

const int MXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, k, ans = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  vector<int> arr(n+1);
  for (int i = 0; i < k; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    arr[a]++;
    arr[b+1]--;
  }
  vector<int> ps(n);
  ps[0] = arr[0];
  for (int i = 1; i < n; ++i) {
    ps[i] = ps[i-1] + arr[i];
  }
  sort(all(ps));
  cout << ps[n/2] << '\n';
}
