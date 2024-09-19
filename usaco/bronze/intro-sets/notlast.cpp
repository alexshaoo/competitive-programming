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

int n, ans = 0;

int main() {
  setIO("notlast");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  string s;
  int c;
  map<string, int> mp = {
    {"Bessie", 0},
    {"Elsie", 0},
    {"Daisy", 0},
    {"Gertie", 0},
    {"Annabelle", 0},
    {"Maggie", 0},
    {"Henrietta", 0}
  };
  while (n--) {
    cin >> s >> c;
    mp[s] += c;
  }
  vector<pair<int, string>> container;
  for (const auto& el : mp) {
    container.push_back({el.second, el.first});
  }
  sort(all(container));
  auto it = upper_bound(all(container), container[0].first, [](const int& value, const pair<int, string>& element) {
    return value < element.first;
  });
  auto nxt = it+1;
  if (nxt != container.end() && nxt->first == it->first) cout << "Tie" << '\n';
  else cout << it->second << '\n';
}
