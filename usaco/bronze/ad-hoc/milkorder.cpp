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

int n, m, k, ans = 0;

int main() {
  // setIO("milkorder");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  vector<int> order(m);
  for (int i = 0; i < m; ++i) {
    cin >> order[i];
  }
  set<int> placed;
  vector<int> cows(n+1, -1);
  unordered_map<int, int> cowPos = {{1, -1}};
  for (int i = 0; i < k; ++i) {
    int cow, pos;
    cin >> cow >> pos;
    cows[pos] = cow;
    placed.insert(cow);
    cowPos[cow] = pos;
  }
  placed.insert(1);
  for (int i = 1; i <= n; ++i) {
    if (cows[i] != -1) continue;
    cows[i] = 1;
    cowPos[1] = i;
    int pos = 1;
    bool possible = true;
    for (int o : order) {
      while (cows[pos] != -1 && cows[pos] != o) {
        ++pos;
      }
      if (placed.count(o) > 0 && cowPos[o] < pos) {
        possible = false;
        break;
      }
      ++pos;
    }
    if (possible) {
      cout << i << '\n';
      return 0;
    }
    cows[i] = -1;
    cowPos[1] = -1;
  }
  cout << "SHOULD NEVER REACH HERE" << '\n';
  return 0;
}
