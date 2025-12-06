#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  unordered_map<int, vector<int>> mp;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a>> b;
    mp[a].push_back(b);
    mp[b].push_back(a);
  }
  
}
