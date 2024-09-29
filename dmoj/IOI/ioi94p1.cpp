#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	int inp[N][N];
	memset(inp, -1, sizeof(inp));
	int ind = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < ind; ++j) {
			cin >> inp[i][j];
		}
		++ind;
	}
	
	for (int i = N-2; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			inp[i][j] += max(inp[i+1][j], inp[i+1][j+1]);
		}
	}
	
	cout << inp[0][0] << '\n';
}