// https://www.facebook.com/codingcompetitions/hacker-cup/2022/qualification-round/problems/A
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

void calc() {
	int N, K;
	cin >> N >> K;
	vector<int> S(N);
	map<int, int> freq;
	
	for (auto &s : S) {
		cin >> s;
		freq[s]++;
	}
	
	int numOnes = 0, numTwos = 0;
	for (const auto &f : freq) {

		// unique 
		if (f.second > 2) {
			cout << "NO" << '\n';
			return;
		}
		
		if (f.second == 1) ++numOnes;
		else ++numTwos;
	}
	
	// exceed K
	if ((numOnes+1)/2 + numTwos > K) cout << "NO" << '\n';
	else cout << "YES" << '\n';
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