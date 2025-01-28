#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		ll L, N;
		cin >> L >> N;
		ll pos = 0, laps = 0, dir = 0;
		while (N--) {
			ll D;
			char C;
			cin >> D >> C;
			if (dir == 0) {
				dir = (C == 'C') ? 1 : -1;
			}
			if (C == 'C') {
				pos += D;
				if (pos >= L) {
					laps += (pos/L);
					pos = (pos%L);
				}
				if (pos == 0) {
					dir = 0;
				} else {
					dir = 1;
				}
			} else if (C == 'A') {
				pos -= D;
				if (pos < 0) {
					laps += (-pos/L);
					pos = (pos%L);
				}
				if (pos == 0) {
					dir = 0;
				} else {
					dir = -1;
				}
			}
		}
		printf("Case #%d: %lld\n", i, laps);
	}
}