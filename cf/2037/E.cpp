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

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve() {
  int n;
  scanf("%d", &n);
  string ans = "";
  int start = -1;
  int ones = 0;
  int last = -1;
  int num;
  for (int i = 1; i < n; ++i) {
    ++ones;
    printf("? 1 %d\n", i + 1);
    fflush(stdout);
    scanf("%d", &num);
    if (num != 0) {
      ones -= num;
      ans += string(ones, '1');
      ans += string(num, '0');
      ans += '1';
      ++i;
      start = i + 1;
      break;
    }
  }
  if (start == -1) {
    printf("! IMPOSSIBLE\n");
    fflush(stdout);
    return;
  }
  for (int i = start; i <= n; ++i) {
    printf("? 1 %d\n", i);
    fflush(stdout);
    int newNum;
    scanf("%d", &newNum);
    if (newNum != num)
      ans += '1';
    else
      ans += '0';
    num = newNum;
  }
  printf("! %s\n", ans.c_str());
  fflush(stdout);
  return;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
