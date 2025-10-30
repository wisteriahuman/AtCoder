N, M, K = map(int, input().split())
P = [0] * N
ans = []

for i in range(K):
	a, b = map(int, input().split())
	P[a - 1] += 1
	if P[a - 1] ==  M:
		ans.append(a)

print(*ans)
