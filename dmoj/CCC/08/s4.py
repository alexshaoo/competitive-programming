from itertools import permutations

N = int(input())

all_cards = []

a = lambda a, b: a + b
s = lambda a, b: a - b
m = lambda a, b: a * b
d = lambda a, b: a // b if b != 0 and (a % b) == 0 else -666

operations = [a, s, m, d]


# """
def hurh():
    best = 0
    
    top = [int(input()) for _ in range(4)]
    
    perms = list(permutations(top))
    
    for perm in perms:
        for op1 in operations:
            for op2 in operations:
                for op3 in operations:
                    w, x, y, z = perm
                    
                    result = op1(op2(w, x), op3(y, z))
                    other = op1(op2(op3(w, x), y), z)
                    
                    if result < other <= 24 or other <= 24 < result:
                        result = other
                    
                    if result == 24:
                        return result
                    
                    elif best < result < 24:
                        best = result
    
    return best


for _ in range(N):
    print(hurh())