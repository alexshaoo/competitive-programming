#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int INF = 0x3f3f3f3f;
typedef long long LL;

int av(int num) {
	return (num >= 0) ? num : num * -1;
}

// check if s1 is bigger than s2 (strings same legnth because of 0 padding)
bool comp(string s1, string s2) {
	for (int i = 0; i < s1.length(); ++i) {
		if (s1.at(i) != s2.at(i)) return s1.at(i) > s2.at(i);
	}
	return false;
}

string op(string s1, string s2, bool add, int l) {
	if (!comp(s1, s2)) {
		string temp;
		temp = s1;
		s1 = s2;
		s2 = temp;
	}
	string ans = "";
	if (add) {
		int carry = 0;
		int sum = 0;
		for (int i = l - 1; i >= 0; --i) {
			sum = (int)s1.at(i) + (int)s2.at(i) + carry - 96;
			// Special c++ data type for handling remainder and quotients
			div_t thing = div(sum, 10);
			ans = to_string(thing.rem) + ans;
			carry = thing.quot;
		}
		if (carry != 0) ans = to_string(carry) + ans;
		return ans;

	} else {
		if (s1 == s2) return "0";
		int diff;
		if (comp(s1, s2)) {
			for (int i = l - 1; i >= 0; --i) {
				diff = (int)s1.at(i) - (int)s2.at(i);
				if (diff < 0) {
					diff += 10;
					if (i != 0) s1.at(i - 1) = (char)((int)s1.at(i - 1) - 1);
				}
				ans = to_string(diff) + ans;
			}

		} else {
			for (int i = l - 1; i >= 0; --i) {
				diff = (int)s2.at(i) - (int)s1.at(i);
				if (diff < 0) {
					diff += 10;
					if (i != 0) s2.at(i - 1) = (char)((int)s2.at(i - 1) - 1);
				}
				ans = to_string(diff) + ans;
			}
		}
		if (ans.at(0) == '0') {
			while (ans.at(0) == '0') ans.erase(0, 1);
		}
		return ans;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string s1, s2;
		char sign1, sign2;
		int l1, l2, d, m;
		cin >> s1 >> s2;
		sign1 = s1.at(0);
		sign2 = s2.at(0);
		if (sign1 == '-') s1.erase(0, 1);
		if (sign2 == '-') s2.erase(0, 1);
		l1 = s1.length();
		l2 = s2.length();
		d = av(l1 - l2);
		m = max(l1, l2);
		if (d != 0) {
			string extra(d, '0');
			if (l1 > l2) s2 = extra + s2;
			else s1 = extra + s1;
		}
		if (sign1 != sign2 && s1 == s2) cout << 0 << "\n";
		else if (sign1 == '-' && sign2 == '-') {
			cout << '-' + op(s1, s2, true, m) << "\n";
		}
		else if (sign1 == '-' && sign2 != '-') {
			if (comp(s1, s2)) cout << '-' + op(s1, s2, false, m) << "\n";
			else cout << op(s1, s2, false, m) << "\n";
		}
		else if (sign1 != '-' && sign2 == '-') {
			if (comp(s1, s2)) cout << op(s1, s2, false, m) << "\n";
			else cout << '-' + op(s1, s2, false, m) << "\n";
		}
		else {
			cout << op(s1, s2, true, m) << "\n";
		}
	}
}

/*
const int MAX = 200001;

int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, W, D;

	cin >> N >> W >> D;

	int A, B, ind;
	vector<vector<int>> walk(MAX + 1);

	for (int i = 0; i < W; ++i) {
		cin >> A >> B;
		walk[B].push_back(A);
	}

	int path[MAX + 1];
	for (int i = 1; i <= N; ++i) {
		cin >> path[i];
		if (path[i] == N) ind = i;
	}

	int time[10];
	memset(time, INF, sizeof(time));
	
	for (int i = 1; i <= ind; ++i) time[path[i]] = ind - i;
	
	bool visited[MAX + 1];
	int curr, t;
	queue<pair<int, int>> q;

	q.push({ N, 0 });

	while (!q.empty()) {
		curr = q.front().first;
		t = q.front().second;
		cout << curr << "\n";
		time[curr] = min(time[curr], t);
		q.pop();
		visited[curr] = true;
		for (int poss : walk[curr]) {
			if (!visited[poss]) q.push({ poss, t + 1 });
		}
	}
	
	for (int ti : time) cout << ti << " ";

}
*/