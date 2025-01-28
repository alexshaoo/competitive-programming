#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long

const int MOD = (LL)1e9 + 7;

LL N, arr[501][501];
LL curr = 1;

LL p(LL a, LL b) {
	if (b == 0) return 1;
	if (b == 1) return a;

	if (b & 1) return a * p(a * a % MOD, b >> 1) % MOD;

	return p(a * a % MOD, b >> 1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {

		// Find index of biggest value in (i+1)-th column
		int idx = i;
		for (int j = i + 1; j < N; ++j) {
			if (arr[idx][i] < arr[j][i]) idx = j;
		}

		// If idx and i are different
		if (idx ^ i) {
			curr *= -1;
			swap(arr[i], arr[idx]);
		}

		// Needed help from a friend for this one
		for (int j = i + 1; j < N; ++j) {
			LL val = arr[j][i] * (LL) p((LL) arr[i][i], MOD - 2) % MOD;
			for (int k = i; k < N; ++k) arr[j][k] = (arr[j][k] - val * arr[i][k]) % MOD;
		}
	}

	// Multiply all diagonal matrix values
	for (int i = 0; i < N; ++i) {
		curr = (curr * arr[i][i]) % MOD;
	}

	// In case negative
	cout << (curr + MOD) % MOD;

}