#include <bits/stdc++.h>

using namespace std;

int N, M, T;

// List of all distances between each person
// 0 - Griffin, 1 - T - hiders 1 to %
int peopleDist[6][6];

// Locations of people
int people[6][2];

// Character input of the school
char school[20][20];

void findShortestDist(int person) {

	int r, c;

	bool visited[20][20];
	fill_n(&visited[0][0], sizeof(visited) / sizeof(**visited), false);

	// Distance from person to each grid in the school
	int dist[20][20];

	// Queue of possible points to search
	queue<vector<int>> q;
	vector<int> pos;

	r = people[person][0];
	c = people[person][1];

	q.push({r, c});
	visited[r][c] = true;

	// Since max possible dist is 209, initialize all distances to 210
	fill_n(&dist[0][0], sizeof(dist) / sizeof(**dist), 210);
	dist[r][c] = 0;

	// Possible neighbour shifts
	int possible[] = {-1, 1};

	while (!q.empty()) {

		pos = q.front();
		r = pos[0];
		c = pos[1];

		q.pop();

		for (int shift : possible) {

			r += shift;

			if (r >= 0 && r < N && !visited[r][c] && school[r][c] != 'X') {

				dist[r][c] = dist[r - shift][c] + 1;
				q.push({r, c});
				visited[r][c] = true;

			}

			r -= shift;
			c += shift;

			if (c >= 0 && c < M && !visited[r][c] && school[r][c] != 'X') {

				dist[r][c] = dist[r][c - shift] + 1;
				q.push({r, c});
				visited[r][c] = true;
			}

			c -= shift;
		}
	}

	for (int i = 0; i < T; ++i) {
		peopleDist[person][i] = dist[people[i][0]][people[i][1]];
		peopleDist[i][person] = dist[people[i][0]][people[i][1]];

	}
}

int main() {

	scanf("%d %d %d", &N, &M, &T);
	scanf("\n");

	// Hider number
	int hider = 0;

	for (int i = 0; i < N; ++i) {

		for (int j = 0; j < M; ++j) {

			scanf("%c", &school[i][j]);

			if (school[i][j] == 'G') {
				people[0][0] = i;
				people[0][1] = j;
			} 

			else if (school[i][j] == 'H') {

				hider++;

				people[hider][0] = i;
				people[hider][1] = j;
			}
		}

		scanf("\n");
	}
	
	vector<int> options;

	for (int i = 0; i <= T; ++i) {

		findShortestDist(i);

		if (i != 0) options.push_back(i);
	}

	int minDist = 0;
	int dist;
	
	for (int i = 0; i < T; ++i) {

		minDist += peopleDist[i][i + 1];
	}
	
	while (next_permutation(options.begin(), options.end())) {

		dist = peopleDist[0][options[0]];

		for (int i = 1; i < T; ++i) {

			dist += peopleDist[options[i - 1]][options[i]];
		}

		if (dist < minDist) minDist = dist;
	}
	
	printf("%d", minDist);
	
}