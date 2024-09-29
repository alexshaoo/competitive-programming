N, T = map(int, input().split())

new_gen = [0 if char == "0" else 1 for char in input()]
old_gen = new_gen[:]
mul = 1

while T != 0:
    
    if T % 2 == 1:
        
        old_gen, new_gen = new_gen, old_gen
        
        for j in range(N):
            
            new_gen[j] = old_gen[(j - mul) % N] ^ old_gen[(j + mul) % N]
    
    T //= 2
    mul *= 2
    
print(*new_gen, sep = "")