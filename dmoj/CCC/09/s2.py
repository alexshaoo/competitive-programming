import copy

lighthouses = []

R = int(input())
L = int(input())

for i in range(R):
    lighthouses.append(list(map(int, input().split())))

combinations = [lighthouses[-1]]

for i in range(1, R):
    
    new = list(copy.deepcopy(lighthouses))
    
    for j in range(i, R):
        
        for col_index in range(L):
            
            if new[j][col_index] == new[j - 1][col_index]:
                new[j][col_index] = 0
            else:
                new[j][col_index] = 1
    
    if new[-1] not in combinations:
        combinations.append(new[-1])

print(len(combinations))