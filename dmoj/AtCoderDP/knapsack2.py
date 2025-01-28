N, W = map(int, input().split())
weights, values = zip(*[[int(data) for data in input().split()] for _ in range(N)])

total_value = sum(values)

dp = [[1000000001] * (total_value + 1) for _ in range(N + 1)]

dp[-1][0] = 0

for i in range(N):
    
    for j in range(total_value + 1):
        
        if j - values[i] < 0:
            
            dp[i][j] = min(dp[i][j], dp[i - 1][j])
            
        else:
            
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - values[i]] + weights[i])
            
for i in range(total_value, -1, -1):
    
    if dp[N - 1][i] <= W:
        
        print(i)
        break