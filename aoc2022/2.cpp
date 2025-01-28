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
	ull one = 0;
	ull two = 0;
  while (getline(cin, line)) {
    int a = line[0] - 'A', b = line[2] - 'X';
    // one
    one += (b+1);
    if (a == b) {
    	one += 3;
    } else if ((b-a+3)%3 == 1) {
    	one += 6;
    }
    // two
    two += ((a+b+2)%3+1);
    two += (3*b);
	}
	cout << one << ' ' << two << '\n';
}