import heapq

l = [1, 2, 3,6, 3, 6, 2, 3, 1, 6, 1]

heapq.heapify(l)
heapq.heappush(l, -1)
heapq.heappop(l)
heapq.heapreplace(l, 183461)
heapq.heapreplace(l, 183461)
heapq.heapreplace(l, 183461)

print(l)
print(l[0])

l[5] = -5

print(l)
print(l[0])

heapq.heapify(l)

print(l)
print(l[0])