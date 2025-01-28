#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int L;
		cin >> L;
		int cost[L+1];
		for (int i = 0; i <= L; ++i) {
			cost[i] = i;
		}
		for (int i = 3; i < L/2; ++i) {
			int j = i;
			int c = 4 + cost[i];
			while (j < L-i+1) {
				c += 2;
				j += i;
				cost[j] = min(cost[j], c);
			}
			for (int k = i; k < L; ++k) {
				cost[k+1] = min(cost[k+1], cost[k] + 1);
			}
		}
		for (int i = 0; i <= L; ++i) {
			cout << i << ' ' << cost[i] << '\n';
		}
		printf("Case #%d: %d\n", t, cost[L]);
	}
}
