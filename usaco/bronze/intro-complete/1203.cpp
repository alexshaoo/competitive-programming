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

const int MXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int T, N, ans = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> N;
    vector<int> arr(N);
    int mx = -1, sm = 0;
    for (int i = 0; i < N; ++i) {
      cin >> arr[i];
      mx = max(mx, arr[i]);
      sm += arr[i];
    }
    if (mx == 0) {
      cout << 0 << '\n';
      continue;
    }
    for (int h = mx; h <= sm; ++h) {
      if (sm % h != 0) continue;
      int part = sm / h;
      int currSum = 0;
      bool worked = true;
      for (int i = 0; i < N; ++i) {
        currSum += arr[i];
        if (currSum > h) {
          worked = false;
          break;
        }
        if (currSum == h) {
          currSum = 0;
        }
      }
      if (worked) {
         cout << N - part << '\n';
         break;
      }
    }
  }
}