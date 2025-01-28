# Note: i & -i is the value of the rightmost 1 in the binary representation of i
# ex. if i = 50, (110010 in binary), i & -i = 2 (10 in binary)


N = int(input())
h = [0] + list(map(int, input().split()))
a = [0] + list(map(int, input().split()))
tree = [0] * (N + 1)


def update(ind, val):
    while ind <= N:
        tree[ind] = max(tree[ind], val)
        ind += ind & -ind


def solve(ind):
    ans = 0
    while ind > 0:
        ans = max(tree[ind], ans)
        ind -= ind & -ind
    return ans


for i in range(1, N + 1):
    div = solve(h[i] - 1)
    update(h[i], div + a[i])

print(max(tree))