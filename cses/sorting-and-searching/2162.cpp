#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  deque<int> dq(n);
  iota(all(dq), 1);

  for (int i = 0; i < n - 1; ++i) {
    int x = dq.front();
    dq.pop_front();
    dq.push_back(x);
    cout << dq.front() << ' ';
    dq.pop_front();
  }

  cout << dq.front() << '\n';
}
