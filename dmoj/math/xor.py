T = int(input())

ranges = []

for i in range(T):
    ranges.append(list(map(int, input().split())))
    
# Finds XOR from 0
def f(number):
    if number % 4 == 0:
        return number
    elif number % 4 == 1:
        return 1
    elif number % 4 == 2:
        return number + 1
    elif number % 4 == 3:
        return 0
    
for tupl in ranges:
    before = f(tupl[0] - 1)
    after = f(tupl[1])
    
    print(after ^ before)