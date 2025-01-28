#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

// N, M, 0 if previous pie not taken, 
int state[3001][101][101][2];
int A[3001];
int B[101];

int move(int a, int bl, int br, bool taken) {

	int &curr = state[a][bl][br][taken];

	/*
	cout << a;
	cout << bl;
	cout << br;
	cout << taken << "\n";
	*/

	if (curr != -1) {
		return curr;
	}

	if (a == 0) {
		if (bl > br) {
			return 0;
		}

		int total = 0;

		if (taken) {
			for (int i = (bl + br) / 2 + 1; i <= br; i++) {
				total += B[i];
			}
		} else {
			for (int i = (bl + br + 1) / 2; i <= br; i++) {
				total += B[i];
			}
		}
		curr += total;
		return curr;
	}

	if (bl > br) {

		if (taken) {
			//cout << move(a - 1, bl, br, false) << endl;
			return curr = move(a - 1, bl, br, false);
		}
		//cout << max(A[a] + move(a - 1, bl, br, true), move(a - 1, bl, br, false)) << endl;
		return curr = max(A[a] + move(a - 1, bl, br, true), move(a - 1, bl, br, false));
	}

	if (taken) {
		//cout << max(move(a - 1, bl, br, false), move(a, bl + 1, br, false)) << endl;
		return curr = max(move(a - 1, bl, br, false), move(a, bl + 1, br, false));
	}

	//cout << max(max(A[a] + move(a - 1, bl, br, true), B[br] + move(a, bl, br - 1, true)), move(a - 1, bl, br, false)) << endl;
	return curr = max(max(A[a] + move(a - 1, bl, br, true), B[br] + move(a, bl, br - 1, true)), move(a - 1, bl, br, false));
}



int main() {

	memset(state, -1, sizeof(state));

	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> B[i];
	}
	sort(B + 1, B + M + 1);

	cout << move(N, 1, M, false);

}