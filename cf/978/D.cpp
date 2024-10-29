#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int maxNonOverlappingZeroSum(vector<int>& a) {
  int n = a.size();
  int prefixSum = 0;
  unordered_set<int> seenSums;
  seenSums.insert(
      0);  // We add 0 to handle subarrays starting from the first element.
  int count = 0;  // To store the count of non-overlapping zero-sum subarrays.

  for (int i = 0; i < n; ++i) {
    prefixSum += a[i];

    // If prefixSum has been seen before, we've found a zero-sum subarray.
    if (seenSums.count(prefixSum)) {
      count++;           // Increment the count of zero-sum subarrays.
      seenSums.clear();  // Clear the set for the next non-overlapping subarray.
      seenSums.insert(0);  // Reinsert 0 for the new subarray search.
      prefixSum = 0;       // Reset the prefix sum for the next segment.
    }
    seenSums.insert(prefixSum);  // Track the current prefix sum.
  }

  return count;
}

int main() {
  int t;  // Number of test cases
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << maxNonOverlappingZeroSum(a) << endl;
  }

  return 0;
}
