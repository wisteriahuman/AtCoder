def dfs(idx: int, now: str):
	if idx == K:
		A.append(now)
		return
	for i in range(N):
		dfs(idx + 1, now + S[i])


N, K, X = map(int, input().split())
S = [input() for _ in range(N)]
A = []
dfs(0, "")
A.sort()
print(A[X - 1])
