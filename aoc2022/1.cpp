#include <bits/stdc++.h>
using namespace std;

#define cl(a, b) memset(a, b, sizeof(a))
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string line;
	vector<ull> lst;
	ull calories = 0;
	while (getline(cin, line)) {
		if (line.empty()) {
			lst.push_back(calories);
			calories = 0;
		} else {
			calories += (ull)stoi(line);
		}
	}
	sort(lst.begin(), lst.end(), greater());
	cout << lst[0] + lst[1] + lst[2] << '\n';
}