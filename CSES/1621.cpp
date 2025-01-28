#include <bits/stdc++.h>
using namespace std;

template <typename T, size_t SIZE>
void print(const T (&array)[SIZE]) {
  for (size_t i = 0; i < SIZE; i++) std::cout << array[i] << " ";
}

template <class ForwardIter>
void print(ForwardIter begin, ForwardIter end) {
  for (; begin != end; ++begin) cout << *begin << " ";
  cout << endl;
}

#define ll long long

const int MXN = 1e5;
const int MOD = 1e9 + 7;

int ans = 0;

int main() {
  ios_base::sync_with_stdio(0);
  int n, x;
  cin >> n;
  set<int> seen;
  while (n--) {
    cin >> x;
    seen.insert(x);
  }
  cout << seen.size() << '\n';
}
