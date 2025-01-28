// this one took way too long. something about the conditions and processing
// messed up my brain - had to cheat and look at how the solution structured

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

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int main() {
  setIO("convention2");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<array<int, 3>> cows(n);  // seniority, a, t
  for (int i = 0; i < n; ++i) {
    cows[i][0] = i;
    cin >> cows[i][1] >> cows[i][2];
  }
  sort(all(cows), [](const array<int, 3>& a, const array<int, 3>& b) {
    return a[1] < b[1];
  });
  ll ans = 0, done = 0;
  set<array<int, 3>> waiting;
  int ci = 0;
  while (ci < n || !waiting.empty()) {
    if (ci < n && cows[ci][1] <= done) {
      waiting.insert(cows[ci]);
      ++ci;
    } else if (waiting.empty()) {
      done = cows[ci][1] + cows[ci][2];
      ++ci;
    } else {
      auto cow = *waiting.begin();
      waiting.erase(waiting.begin());
      ans = max(ans, done - cow[1]);
      done += cow[2];
    }
  }
  cout << ans << '\n';
}
