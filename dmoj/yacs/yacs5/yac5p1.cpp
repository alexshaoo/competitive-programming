#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;

int main() {
	int N, K, X;
	cin >> N >> K >> X;
	
	int co[N];
	
	int prev = 1;
  co[0] = prev;

  for (int i = 1; i < N; ++i) {
      co[i] = (prev * (N - i)) / i;
      prev = co[i];
  }
  
  for (auto num : co) {
  	
  }
	
}