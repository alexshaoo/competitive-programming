// cph chapter 5

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

void printArr(vector<int> arr) {
  for (int el : arr) cout << el << ' ';
  cout << '\n';
}

void recursiveGenerate(vector<int> subset, int n, int k) {
  if (k == n) {
    printArr(subset);
  } else {
    recursiveGenerate(subset, n, k + 1);
    subset.push_back(k);
    recursiveGenerate(subset, n, k + 1);
    subset.pop_back();
  }
}

void subset1(int n) {
  vector<int> subset;
  recursiveGenerate(subset, n, 0);
}

// bit method is cleaner in a lot of cases
void subset2(int n) {
  for (int b = 0; b < (1 << n); ++b) {
    vector<int> subset;
    for (int i = 0; i < n; ++i) {
      if (b & (1 << i)) subset.push_back(i);
    }
    printArr(subset);
  }
}

void permutation1(vector<int> permutation, vector<int> chosen, int n) {
  if ((int)permutation.size() == n) {
    printArr(permutation);
  } else {
    for (int i = 0; i < n; ++i) {
      if (chosen[i]) continue;
      chosen[i] = true;
      permutation.push_back(i);
      permutation1(permutation, chosen, n);
      chosen[i] = false;
      permutation.pop_back();
    }
  }
}

// just use the built-in c++ method, above is for languages that don't have it
// built in this is nice because it works with a lot of things (lexicographical
// string orderings, etc)
void permutation2(int n) {
  vector<int> permutation(n);
  iota(all(permutation), 0);
  do {
    printArr(permutation);
  } while (next_permutation(all(permutation)));
}

// n queens problem
int queensHelper(int y, int n, vector<int>& col, vector<int>& diag1,
                 vector<int>& diag2) {
  if (y == n) {
    return 1;
  }
  int c = 0;
  for (int x = 0; x < n; ++x) {
    if (col[x] || diag1[x + y] || diag2[(x - y) + (n - 1)]) continue;
    col[x] = diag1[x + y] = diag2[(x - y) + (n - 1)] = true;
    c += queensHelper(y + 1, n, col, diag1, diag2);
    col[x] = diag1[x + y] = diag2[(x - y) + (n - 1)] = false;
  }
  return c;
}
void queens(int n) {
  vector<int> col(n), diag1(2 * n), diag2(2 * n);
  cout << queensHelper(0, n, col, diag1, diag2) << '\n';
}

// really fun question, number of paths in an nxn grid, starting from top left
// and going to bottom right optimizations given in book are interesting but
// intuitive and easy to understand
bool valid(int n, int r, int c, vector<vector<bool>>& occupied) {
  return r >= 0 && c >= 0 && r < n && c < n && !occupied[r][c];
}
vector<pair<int, int>> directions = {{0, 1},  {1, 0}, {0, -1},
                                     {-1, 0}, {0, 1}, {1, 0}};
bool allOccupied(vector<vector<bool>>& occupied) {
  for (auto r : occupied) {
    for (bool b : r) {
      if (!b) return false;
    }
  }
  return true;
}

ll pathsHelper(int n, int r, int c, vector<vector<bool>>& occupied) {
  if (r == n - 1 && c == n - 1) {
    if (allOccupied(occupied)) return 1;
    return 0;
  }
  ll count = 0;
  for (int i = 1; i <= 4; ++i) {
    auto [dr, dc] = directions[i];
    r += dr;
    c += dc;
    if (valid(n, r, c, occupied)) {
      if (!valid(n, r + dr, c + dc, occupied) &&
          valid(n, r + directions[i - 1].first, c + directions[i - 1].second,
                occupied) &&
          valid(n, r + directions[i + 1].first, c + directions[i + 1].second,
                occupied))
        continue;

      occupied[r][c] = true;
      count += pathsHelper(n, r, c, occupied);
      occupied[r][c] = false;
    }
    r -= dr;
    c -= dc;
  }
  return count;
}

void paths(int n) {
  vector<vector<bool>> occupied(n, vector<bool>(n, false));
  occupied[0][0] = true;
  // assume always go down, symmetric about the diag
  occupied[1][0] = true;
  cout << 2 * pathsHelper(n, 1, 0, occupied) << '\n';
}

int main() {
  // subsets
  // subset1(5);
  // subset2(5);
  // permutations
  // vector<int> permutation, chosen(5);
  // permutation1(permutation, chosen, 5);
  // permutation2(5);
  // queens(8);
  paths(7); // still too slow and TLEs, optimize further
}