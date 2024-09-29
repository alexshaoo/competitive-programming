def f(x, p, d, w):
    # print(p, w, d)
    if p - d <= x <= p + d:
        return 0
    elif x + d < p:
        return w * (p - d - x)
    return w * (x - p - d)


N = int(input())
P, W, D = zip(*[[int(data) for data in input().split()] for _ in range(N)])

MINP, MAXP = min(P), max(P)
l, r = MINP, MAXP

while l < r:
    mid = (l + r) // 2
    if mid == l:
        break
    before, curr = 0, 0
    for p, d, w in zip(P, D, W):
        before += f(mid - 1, p, d, w)
        curr += f(mid, p, d, w)
    if before > curr:
        l = max(mid, l + 1)
    else:
        r = min(mid, r - 1)

print(sum([f(l, p, d, w) for p, d, w in zip(P, D, W)]))