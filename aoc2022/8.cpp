#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> V;

// Find the trees that are visible from a given tree in a given direction.
// Returns a list of trees in the given direction.
V rays(const vector<V>& grid, int i, int j, int di, int dj) {
  V ray;
  while (true) {
    i += di;
    j += dj;
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        grid[i][j] >= grid[i - di][j - dj])
      break;
    ray.push_back(grid[i][j]);
  }
  return ray;
}

int main() {
  // Read the grid of tree heights.
  vector<V> grid;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    V row(m);
    for (int j = 0; j < m; ++j) {
      cin >> row[j];
    }
    grid.push_back(row);
  }

  // Compute the scenic score for each tree and find the maximum scenic score.
  int max_score = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      // Find the trees that are visible from the current tree in each direction.
      V rays_up = rays(grid, i, j, -1, 0);
      V rays_down = rays(grid, i, j, 1, 0);
      V rays_left = rays(grid, i, j, 0, -1);
      V rays_right = rays(grid, i, j, 0, 1);
      // Compute the scenic score for the current tree.
      int score = rays_up.size() * rays_down.size() * rays_left.size() *
                  rays_right.size();
      max_score = max(max_score, score);
    }
  }

  // Print the maximum scenic score.
  cout << max_score << endl;

  return 0;
}