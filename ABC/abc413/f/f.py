import heapq


H, W, K = map(int, input().split())
goals = []
for _ in range(K):
    r, c = map(lambda x: int(x) - 1, input().split())
    goals.append((r, c))
INF = 10**9
dist = [[INF] * W for _ in range(H)]
small1 = [[INF] * W for _ in range(H)]
small2 = [[INF] * W for _ in range(H)]
used = [[False] * W for _ in range(H)]
hq = []
for i, j in goals:
    dist[i][j] = 0
    heapq.heappush(hq, (0, i, j))

d = [(-1, 0), (1, 0), (0, -1), (0, 1)]
while hq:
    cnt, i, j = heapq.heappop(hq)
    if used[i][j] or dist[i][j] != cnt:
        continue
    used[i][j] = True
    for di, dj in d:
        ni, nj = i + di, j + dj
        if not (0 <= ni < H and 0 <= nj < W):
            continue
        if used[ni][nj]:
            continue
        if cnt < small1[ni][nj]:
            small2[ni][nj], small1[ni][nj] = small1[ni][nj], cnt
        elif cnt < small2[ni][nj]:
            small2[ni][nj] = cnt
        if small2[ni][nj] < INF:
            nd = small2[ni][nj] + 1
            if nd < dist[ni][nj]:
                dist[ni][nj] = nd
                heapq.heappush(hq, (nd, ni, nj))

ans = 0
for i in range(H):
    for j in range(W):
        if dist[i][j] < INF:
            ans += dist[i][j]
print(ans)
