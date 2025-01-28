#include <bits/stdc++.h>
using namespace std;

const int MAXN = 150010
, MAXM = 150010, MAXZ = 18;
int N, M;
int diff[17][MAXN], normalTree[MAXZ][MAXN];
int x[MAXM], y[MAXM], z[MAXM];

int lcm(int x, int y) { 
	return x*y / __gcd(x, y);
}

int query(int x, int y) {
  int k = log2(y - x + 1);
  return __gcd(normalTree[k][x], normalTree[k][y-(1<<k)+1]);
}

int main() {
	
  scanf("%d %d", &N, &M);
  
  for (int i = 1; i <= M; ++i) {
    scanf("%d %d %d", &x[i], &y[i], &z[i]);
    ++diff[z[i]][x[i]]; 
    --diff[z[i]][y[i]+1];
  }
  
  for (int i = 1; i <= N; ++i) {
    int x = 1;
    for (int j = 1; j <= 16; ++j) {
      diff[j][i] += diff[j][i-1];
      if (diff[j][i] > 0) x = lcm(x, j);
    }
    
    normalTree[0][i] = x;
  }
  
  for (int i = 1; i < MAXZ; ++i) {
  	for (int j = 1; j + (1<<i) - 1 <= N; ++j) {
    	normalTree[i][j] = __gcd(normalTree[i-1][j], normalTree[i-1][j+(1<<(i-1))]);
    }
  }
  
  for (int i = 1; i <= M; ++i) {
    if (query(x[i], y[i]) != z[i]) { 
    	cout << "Impossible\n"; 
    	return 0;
    }
  }
  
  for (int i = 1; i <= N; ++i) {
  	cout << normalTree[0][i] << " ";
  }
  cout << "\n";
}
