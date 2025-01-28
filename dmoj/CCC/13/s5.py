N = int(input())

cost = 0

while N != 1:
    lim = int(N ** 0.5)
    
    test = 2
    
    while test <= lim:
        if N % test == 0:
            break
        
        test += 1
    
    if test > lim:
        N -= 1
        cost += N
        
    else:
        N -= N // test
        cost += test - 1

print(cost)