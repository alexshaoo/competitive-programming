N = int(input())

g = [[] for _ in range(N + 1)]

MOD = int(1e9 + 7)

for i in range(N - 1):
    x, y = map(int, input().split())

    g[x].append(y)
    g[y].append(x)

visited = [False] * (N + 1)

q = [1]
dir = []

while q:
    curr = q.pop()
    visited[curr] = True
    dir.append(curr)
    for neighbour in g[curr]:
        if not visited[neighbour]:
            q.append(neighbour)

# so the lists don't share the same memory or whatever bug that was
coloured = [1] * (N + 1)
not_coloured = [1] * (N + 1)

while dir:
    curr = dir.pop()
    visited[curr] = 0
    for neighbour in g[curr]:
        if not visited[neighbour]:
            coloured[curr] = (coloured[curr] * not_coloured[neighbour]) % MOD
            not_coloured[curr] = (not_coloured[curr] * (coloured[neighbour] + not_coloured[neighbour]) % MOD) % MOD
            #print(coloured, not_coloured)
print((coloured[1] + not_coloured[1]) % MOD)