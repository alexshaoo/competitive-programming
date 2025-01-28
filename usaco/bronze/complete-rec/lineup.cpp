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

int n, ans = 0;
vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

int main() {
  setIO("lineup");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<pair<string, string>> constraints;
  for (int i = 0; i < n; ++i) {
    string tmp, f, s;
    cin >> f >> tmp >> tmp >> tmp >> tmp >> s;
    if (f > s) swap(f, s);
    constraints.push_back({f, s});
  }
  sort(constraints.begin(), constraints.end());
  do {
    int req = 0;
    bool valid = true;
    while (req < n) {
      auto it1 = find(cows.begin(), cows.end(), constraints[req].first);
      auto it2 = find(cows.begin(), cows.end(), constraints[req].second);
      if (abs(distance(it1, it2)) != 1) {
        valid = false;
        break;
      }
      ++req;
    }
    if (valid) {
      for (const auto& cow : cows) cout << cow << '\n';
      return 0;
    }
  } while (next_permutation(cows.begin(), cows.end()));
}
