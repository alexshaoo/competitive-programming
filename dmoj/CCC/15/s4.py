first_line = list(map(int, input().split()))

K = first_line[0]
N = first_line[1]
M = first_line[2]

adj = [[] for i in range(N + 1)]

for i in range(M):
    info = list(map(int, input().split()))
    
    a = info[0]
    b = info[1]
    t = info[2]
    h = info[3]
    
    adj[a].append([b, t, h])
    adj[b].append([a, t, h])
    
last_line = list(map(int, input().split()))
A = last_line[0]
B = last_line[1]

# List of shortest times
times = [[1000000000 for i in range(K + 1)] for j in range(N + 1)]
    
for i in range(K + 1):
    times[A][i] = 0
    
visited = [False] * (N + 1)

q = [A]

while len(q) > 0:
    
    current = q.pop(0)
    
    visited[current] = False
    
    for island in adj[current]:
        for i in range(K - island[2] + 1):
            if times[current][i] + island[1] < times[island[0]][i + island[2]]:
                times[island[0]][i + island[2]] = times[current][i] + island[1]
                
                if not visited[island[0]]:
                    q.append(island[0])
                    visited[island[0]] = True
                    

if times[B][K - 1] > 999999999:
    print(-1)
else:
    print(times[B][K - 1])