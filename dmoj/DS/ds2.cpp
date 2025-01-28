#include <bits/stdc++.h>
using namespace std;

#define cl(a, b) memset(a, b, sizeof(a))
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

int N, M, ds[MAXN], g[MAXN] = {0};

int find(int c) {
	if (ds[c] == c) {
		return c;
	}
	return ds[c] = find(ds[c]);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	vector<int> hargun;
	for (int i = 1; i <= N; ++i) {
		ds[i] = i;
	}
	int u, v, fu, fv;
	for (int i = 0; i < M; ++i) {
		cin >> u >> v;
		fu = find(u);
		fv = find(v);
		if (fu != fv) {
			if (g[fu] > g[fv]) {
				ds[fv] = fu;
			} else {
				if (g[fu] == g[fv]) {
					++g[fv];
				}
				ds[fu] = fv;
			}
			hargun.push_back(i + 1);
		}
	}
	if (hargun.size() != N-1) {
		cout << "Disconnected Graph" << '\n';
	} else {
		for (auto& ryan : hargun) {
			cout << ryan << '\n';
		}
	}
}