#include <bits/stdc++.h>

typedef long long ll;
const int MAXN = 101;

using namespace std;

int N;
int triangle[MAXN][MAXN];
int dp[MAXN][MAXN];

int findMax(int r, int c) {
	
	// solved already
	if (dp[r][c] != -1) return dp[r][c];
	
	// reached edge of triangle
	if (r == N || c == N) {
		return dp[r][c] = 
	}
}

int main() {
	
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			scanf("%d", &triangle[i][j]);
		}
	}
	
	
}