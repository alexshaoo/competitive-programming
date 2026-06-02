#include <bits/stdc++.h>
using namespace std;

// range for each element ending at k is (k - p(k), k], where p(k) is largest
// power of 2 | k) p(k) can be calculated with k & -k
struct BIT {
  int n;
  vector<int> tree;

  BIT(int n) {
    this->n = n;
    tree.assign(n + 1, 0); // 1-indexed
  }

  BIT(const vector<int> &arr) { // build BIT from 0-indexed array
    n = arr.size();
    tree.assign(n + 1, 0);
    // 0-indexed -> 1-indexed
    for (int i = 0; i < n; ++i)
      tree[i + 1] = arr[i];
    // build
    for (int i = 1; i <= n; ++i) {
      int parent = i + (i & -i);
      if (parent <= n)
        tree[parent] += tree[i];
    }
  }

  void update(int k, int x) {
    while (k <= n) {
      tree[k] += x;
      k += k & -k;
    }
  }

  int sum(int k) {
    int s = 0;
    while (k >= 1) {
      s += tree[k];
      k -= k & -k;
    }
    return s;
  }

  int sum(int l, int r) { return sum(r) - sum(l - 1); }

  void print() {
    for (int x : tree)
      cout << x << ' ';
    cout << '\n';
  }
};

// BIT
int main() {
  vector<int> arr = {1, 3, 4, 8, 6, 1, 4, 2};
  BIT fenwick(arr);
  fenwick.print();
  fenwick.update(3, 5);
  fenwick.print();
}
