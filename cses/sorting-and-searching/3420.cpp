#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  unordered_set<int> s;
  ll sm = 0;
  int n;
  cin >> n;
  deque<int> dq;
  while (n--) {
    int x;
    cin >> x;
    while (s.contains(x)) {
      s.erase(dq.front());
      dq.pop_front();
    }
    s.insert(x);
    dq.push_back(x);
    sm += s.size();
  }
  cout << sm << '\n';
}
