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

const int MXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int k, n, ans = 0;

int main() {
  setIO("race");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> k >> n;
  while (n--) {
    int x;
    cin >> x;
    int speed = 0;
    int dist = 0;
    ans = 0;
    while (1) {
      ++speed;
      dist += speed;
      ++ans;
      if (dist >= k) {
        cout << ans << '\n';
        break;
      }
      if (speed >= x) {
        dist += speed;
        ++ans;
        if (dist >= k) {
          cout << ans << '\n';
          break;
        }
      }
    }
  }
}
