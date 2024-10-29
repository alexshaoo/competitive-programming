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

bool sus(int n) {
  printf("? %d %d\n", n - 1, n);
  fflush(stdout);
  int a, b;
  cin >> a;
  printf("? %d %d\n", n, n - 1);
  fflush(stdout);
  cin >> b;
  if (a == b) {
    return 0;
  }
  printf("? %d %d\n", n - 2, n);
  fflush(stdout);
  cin >> a;
  printf("? %d %d\n", n, n - 2);
  fflush(stdout);
  cin >> b;
  if (a == b) {
    printf("! %d\n", n - 1);
    fflush(stdout);
  } else {
    printf("! %d\n", n);
    fflush(stdout);
  }
  return 1;
}

void solve(int n) {
  if (n == 1) {
    cout << "! 1" << endl;
    return;
  }
  if (n == 2) {
    cout << "? 2 3" << endl;
    int a, b;
    cin >> a;
    cout << "? 3 2" << endl;
    cin >> b;
    if (a == b) {
      cout << "! 1" << endl;
    } else {
      cout << "! 2" << endl;
    }
    return;
  }
  if (sus(n)) {
    return;
  }
  solve(n - 2);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    solve(n);
  }
}
