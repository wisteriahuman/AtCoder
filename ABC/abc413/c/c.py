from collections import deque

Q = int(input())
A = deque()
for _ in range(Q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        c, x = query[1], query[2]
        A.append((x, c))
    elif query[0] == 2:
        k = query[1]
        ans = 0
        while k > 0:
            val, cnt = A[0]
            if cnt <= k:
                ans += val * cnt
                k -= cnt
                A.popleft()
            else:
                ans += val * k
                A[0] = (val, cnt - k)
                k = 0
        print(ans)