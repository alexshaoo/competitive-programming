ops = [[2, 1, 0, 2], [1, 1, 1, 1], [0, 0, 2, 1], [0, 3, 0, 0], [1, 0, 0, 1]]

state = [[[[False for i in range(31)] for j in range(31)] for k in range(31)] for l in range(31)]


def isWinning(particles):
    p1, p2, p3, p4 = particles
    
    if min(particles) < 0 or state[p1][p2][p3][p4]:
        return True
    
    for op in ops:
        
        new = list(original - final for original, final in zip(particles, op))
        A, B, C, D = new
        
        if min(new) >= 0 and not state[A][B][C][D] and not isWinning([A, B, C, D]):
            state[p1][p2][p3][p4] = True
            return True
    
    return False


for _ in range(int(input())):
    
    if isWinning(list(map(int, input().split()))):
        print("Patrick")
    else:
        print("Roland")