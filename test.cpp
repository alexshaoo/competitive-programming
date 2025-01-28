#include <bits/stdc++.h>
using namespace std;

#define sz(x) (x).size()

string s;
int m;
set<int> dif;
multiset<int> ret;

void modify(int x) {
  if (x == 0 || x == sz(s)) return;
  auto it = dif.find(x);
  if (it != end(dif)) {  // x is currently present in dif, remove it
    int a = *prev(it), b = *next(it);
    cout << x - a << ' ' << b - x << '\n';
    cout << "found " << a << ' ' << b << '\n';
    ret.erase(ret.find(x - a)),
        ret.erase(ret.find(b - x));  // update ret
    ret.insert(b - a);
    dif.erase(it);             // remove x from dif
  } else {                     // x is not currently in dif, insert it
    it = dif.insert(x).first;  // insert x into dif
    // it = iterator corresponding to x
    int a = *prev(it), b = *next(it);
    cout << "not found " << a << ' ' << b << '\n';
    ret.erase(ret.find(b - a));  // update ret
    ret.insert(x - a), ret.insert(b - x);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> s >> m;
  dif.insert(0);
  dif.insert(sz(s));
  for (int i = 0; i < sz(s) - 1; ++i)
    if (s[i] != s[i + 1]) dif.insert(i + 1);  // initialize dif
  for (auto it = dif.begin(); next(it) != dif.end(); it++) {
    ret.insert(*next(it) - *it);  // initialize ret
  }
  for (auto it = ret.begin(); it != ret.end(); ++it) {
    cout << *it << ' ';
  }
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;  // 1-indexed position
    modify(x - 1);
    modify(x);
  }
}