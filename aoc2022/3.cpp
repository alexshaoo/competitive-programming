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
	int one = 0;
	int m = line.size()/2;
	string first = line.substr(0, m);
	string second = line.substr(m);
	unordered_map<char, int> f;
	unordered_map<char, int> s;
	for (int i = 0; i < m; ++i) {
		f[first[i]]++;
		s[second[i]]++;
	}
	for (auto it : f) {
		if (s.find(it.first) != s.end()) {
			if (it.first >= 'a' && it.first <= 'z') {
				one += (it.first-'a'+1);
			} else {
				one += (it.first-'A'+27);
			}
		}
	}
	return one;
}

int p2(string line) {
	string first = line, second, third;
	getline(cin, second, '\n');
  getline(cin, third, '\n');
  int two = 0;
	bool done = false;
  for (ull i = 0; i < first.length() && !done; i++) {
    if (second.find(first[i]) != string::npos && third.find(first[i]) != string::npos) {
      char c = first[i];
      if (c >= 'a' && c <= 'z') {
        two += c - 'a' + 1;
      } else if (c >= 'A' && c <= 'Z') {
        two += c - 'A' + 27;
      }
      done = true;
    }
  }
  return two;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string line;
	ull one = 0;
	ull two = 0;
  while (getline(cin, line)) {
  	// one += p1(line);
  	two += p2(line);
	}
	cout << one << ' ' << two << '\n';
}