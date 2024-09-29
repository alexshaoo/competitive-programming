import sys

input = sys.stdin.readline


def merge(start, mid, end, arr):
    i = j = 0
    k = start
    
    # i -> l, j -> r, k -> arr
    
    l = arr[start:mid + 1]
    r = arr[mid + 1:end + 1]
    
    ll = len(l)
    lr = len(r)
    
    # Counter variable
    c = 0
    
    while i < ll and j < lr:
        if l[i] > r[j]:
            arr[k] = r[j]
            j += 1
            k += 1
            c += (ll - i)
        
        else:
            arr[k] = l[i]
            i += 1
            k += 1
    
    if i >= ll:
        while j < lr:
            arr[k] = r[j]
            j += 1
            k += 1
    
    elif j >= lr:
        while i < ll:
            arr[k] = l[i]
            i += 1
            k += 1
    
    return c


def sort(start, end, arr):
    global count
    
    if start >= end:
        return
    
    mid = start + (end - start) // 2
    
    sort(start, mid, arr)
    sort(mid + 1, end, arr)
    
    count += merge(start, mid, end, arr)


t = int(input())

s = []

count = 0

for _ in range(t):
    s.append(int(input()))

sort(0, len(s) - 1, s)

print("%.2f" % ((count + t) / t))