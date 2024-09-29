#include <bits/stdc++.h>
using namespace std;

#define cl(a, b) memset(a, b, sizeof(a))
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int mod = 1e9 + 7;

int p1(string line) {
	int a, b, c, d;

  stringstream ss(line);
  ss >> a;
  ss.ignore();
  ss >> b;
  ss.ignore();
  ss >> c;
  ss.ignore();
  ss >> d;

	if ((a <= c && b >= d) || (a >= c && b <= d)) {
		return 1;
	}
  return 0;
}

int p2(string line) {
	int a, b, c, d;

  stringstream ss(line);
  ss >> a;
  ss.ignore();
  ss >> b;
  ss.ignore();
  ss >> c;
  ss.ignore();
  ss >> d;

	if (a <= c && b >= c) {
		return 1;
	} else if (c <= a && d >= a) {
		return 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string line;
	ull one = 0;
	ull two = 0;
  while (getline(cin, line)) {
  	one += p1(line);
  	two += p2(line);
	}
	cout << one << ' ' << two << '\n';
}