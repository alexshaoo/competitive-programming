N = int(input())
P = 1000000007

def pow(a, b, c, n):
    
    if n <= 1:
        return 1, 1, 0
    
    a, b, c = pow(a, b, c, n // 2)
    a, b, c = (a * a + b * b) % P, (a * b + b * c) % P, (b * b + c * c) % P
    
    if n & 1:
        a, b, c = (a + b) % P, a, b
        
    return a, b, c

print(pow(1, 0, 0, (N - 1) % 2000000016)[0])