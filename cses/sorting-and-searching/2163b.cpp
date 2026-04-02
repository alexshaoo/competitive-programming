#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  ordered_set ost;
  for (int i = 0; i < n; ++i)
    ost.insert(i);

  int pos = 0;
  for (int i = 0; i < n; ++i) {
    // skip k
    pos = (pos + k) % (n - i);
    auto it = ost.find_by_order(pos);
    cout << *it + 1 << ' ';
    ost.erase(it);
  }

  cout << '\n';
}
