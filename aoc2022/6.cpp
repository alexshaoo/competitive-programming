#include <bits/stdc++.h>
using namespace std;

#define cl(a, b) memset(a, b, sizeof(a))
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int mod = 1e9 + 7;

int distinct(string line, int length) {
  int i = length;
  while (i <= line.length()) {
	  set<char> s(line.begin() + i-length, line.begin() + i);
	  if (s.size() == length) {
		  return i;
	  }
	  ++i;
  }
  return -1;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string line;
	ull one = 0;
	ull two = 0;
  while (getline(cin, line)) {
  	one += distinct(line, 4);
  	two += distinct(line, 14);
	}
	cout << one << ' ' << two << '\n';
}