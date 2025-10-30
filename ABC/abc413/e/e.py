def dfs(a, b):
    if b == 0:
        return [P[a]]
    
    mid = 1 << (b - 1)
    left = dfs(a, b - 1)
    right = dfs(a + mid, b - 1)
    if left + right <= right + left:
        return left + right
    else:
        return right + left

T = int(input())
for _ in range(T):
    N = int(input())
    P = list(map(int, input().split()))
    ans = dfs(0, N)
    print(*ans)