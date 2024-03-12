// 8/15 i don't know what's wrong

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(int n, vector<int> a, vector<int> b) {
  vector<int> keep, left, right;
  int i = 0, j = 0;
  while (i < n && j < n) {
    if (a[i] == b[j]) {
      keep.push_back(i);
      left.push_back(j);
      while (a[i] == b[j]) ++j;
      right.push_back(j - 1);
    }
    ++i;
  }
  if (j < n) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
  vector<string> ans;
  for (int i = 0; i < keep.size(); ++i) {
    if (left[i] != keep[i])
      ans.push_back("L " + to_string(left[i]) + " " + to_string(keep[i]));
  }
  for (int i = keep.size() - 1; i >= 0; --i) {
    if (keep[i] != right[i])
      ans.push_back("R " + to_string(keep[i]) + " " + to_string(right[i]));
  }
  cout << ans.size() << '\n';
  for (auto& thing : ans) {
    cout << thing << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a, b;
  for (int i = 0; i < n; ++i) {
    int aa;
    cin >> aa;
    a.push_back(aa);
  }
  for (int i = 0; i < n; ++i) {
    int bb;
    cin >> bb;
    b.push_back(bb);
  }
  solve(n, a, b);
}