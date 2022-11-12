#include <bits/stdc++.h>
using namespace std;

const int MAXL = 1e5+5;

int main() {
	int T;
	cin >> T;
	int cost[MAXL+1];
	for (int i = 0; i <= MAXL; ++i) {
		cost[i] = i;
	}
	for (int i = 2; i < MAXL/2; ++i) {
		int j = i;
		int c = 4 + cost[i];
		while (j < MAXL-i+1) {
			c += 2;
			j += i;
			cost[j] = min(cost[j], c);
		}
	}
	for (int t = 1; t <= T; ++t) {
		int L;
		cin >> L;
		printf("Case #%d: %d\n", t, cost[L]);
	}
}