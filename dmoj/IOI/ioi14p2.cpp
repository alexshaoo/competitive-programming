#include <algorithm>
using namespace std;

const int limit = 1 << 21;
const int siz = 1 << 22;
 
int up[siz], down[siz];
int n, k, opr, lft, rght, hgt;

void merge(int childNode, int d, int u) {

	up[childNode] = min(d, max(u, up[childNode]));
	down[childNode] = max(u, min(d, down[childNode]));
}
 
void build(int node, int height, int op) {
	if (op == 1) {

		up[node] = max(height, up[node]);
		down[node] = max(height, down[node]);
	}
	if (op == 2) {
		up[node] = min(height, up[node]);
		down[node] = min(height, down[node]);
	}
}

void update(int l, int r, int ln, int rn, int t, int h, int n) {
    if (l > rn || r < ln) return;
    if (l >= ln && r <= rn) {
        build(n,h,t);
        return;
    }
    merge(2 * n, down[n], up[n]);
    merge(2 * n + 1, down[n], up[n]);
    down[n] = siz, up[n] = 0;
    int mid = l + (r - l) / 2;
    update(l, mid, ln, rn, t, h, 2 * n);
    update(mid + 1, r, ln, rn, t, h, 2 * n + 1);
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]) {
	for (int i = 0; i < k; ++i) update(1, limit, left[i] + 1, right[i] + 1, op[i], height[i], 1);
	for (int i = 1; i < limit; ++i) {
		merge(2 * i, down[i], up[i]);
		merge(2 * i + 1, down[i], up[i]);
	}
	for (int i = limit; i < limit + n; ++i) finalHeight[i - limit] = min(up[i], down[i]);
}