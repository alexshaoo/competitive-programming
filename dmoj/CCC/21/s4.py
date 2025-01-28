from sys import stdin
from heapq import heappush, heappop
input = stdin.readline

N, W, D = map(int, input().split())
adj = []
pre = [-1] * (N + 1)
for _ in range(W):
    a, b = map(int, input().split())
    adj.append((a, pre[b]))
    pre[b] = len(adj) - 1

print(adj, pre)

perm = list(map(int, input().split()))
DIST = [N] * (N + 1)
DIST[N] = 0
queue = [N]
for node in queue:
    cur = pre[node]
    while cur != -1:
        nxt, cur = adj[cur]
        if DIST[nxt] == N:
            DIST[nxt] = DIST[node] + 1
            queue.append(nxt)

print(DIST)

ans = []
for i, j in enumerate(perm):
    heappush(ans, (i + DIST[j], i))

print(ans)

out = []
for _ in range(D):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    perm[x], perm[y] = perm[y], perm[x]
    heappush(ans, (x + DIST[perm[x]], x))
    heappush(ans, (y + DIST[perm[y]], y))
    while 1:
        val, i = ans[0]
        if i + DIST[perm[i]] == val:
            out.append(val)
            break
        heappop(ans)

print("\n".join(map(str, out)))
