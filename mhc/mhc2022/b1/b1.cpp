// https://www.facebook.com/codingcompetitions/hacker-cup/2022/qualification-round/problems/B1
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

void calc() {
	int R, C;
	bool tree = false;
	cin >> R >> C;
	vector<string> m(R);
	
	for (auto &r : m) 
		cin >> r;
	
	for (const auto &r : m) {
		if (r.find('^') != std::string::npos) 
			tree = true;
	}
	
	if (tree && (R == 1 || C == 1)) {
		cout << "Impossible" << '\n';
		return;
	}
	
	// possible for nonzero tree count
	if (tree) {
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j) 
				m[i][j] = '^';
	}
	
	cout << "Possible" << '\n';
	for (const auto &r : m) 
		cout << r << '\n';
}

int main() {
	int T, i = 1;
	cin >> T;
	
	while (i <= T) {
		cout << "Case #" << i << ": ";
		calc();
		++i;
	}
}