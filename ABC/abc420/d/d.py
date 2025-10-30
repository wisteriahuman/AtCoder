from collections import deque

def Dprint():
	print()
	for i in range(H):
		for j in range(W):
			print(dist[i][j], end=", ")
		print()
	print()

H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]

"""[o, x, ?] -> ."""
for i in range(H):
	for j in range(W):
		if (A[i][j] == "S"):
			S = [i, j]
		if (A[i][j] == "G"):
			G = [i, j]
		if (A[i][j] in ["o", "x", "?"]):
			A[i][j] = "."

d = ((-1, 0), (1, 0), (0, -1), (0, 1))
dist = [[-1] * W for _ in range(H)]
dq = deque()

dist[S[0]][S[1]] = 0
dq.append(S)

Dprint()

while dq:
	now_i, now_j = dq.popleft()

	for dy, dx in d:
		next_i, next_j = now_i + dy, now_j + dx

		if not(0 <= next_i < H and 0 <= next_j < W):
			continue
		if A[next_i][next_j] == "#":
			continue
		if dist[next_i][next_j] != -1:
			continue

		dist[next_i][next_j] = dist[now_i][now_j] + 1
		dq.append([next_i, next_j])

		Dprint()


# 答え出力
# print(dist[G[0]][G[1]])
