N, K = [int(x) for x in input().split()]
attractions = [int(x) for x in input().split()]

dp =  [0] * (2 * N)
i = 0
for attraction in attractions:
    dp[i] = max(attraction, dp[i - 1] * (i // K == (i - 1) // K))
    i += 1

for i in range((N - 1) // K):
    x, y, s = 0, 0, 0
    j = i * K + K
    while j > i * K:
        j -= 1
        y = max(y, dp[j])
        x = max(x, dp[j] + s)
        s = max(s, attractions[j])
        dp[j + K] = max(x, y + dp[j + K])

print(dp[N-1])