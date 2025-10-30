N = int(input())
V = list(map(int, input().split()))
C = list(map(int, input().split()))
ans = 0
for i in range(1 << N):
	X, Y = 0, 0
	for j in range(N):
		if (i >> j) & 1:
			X += V[j]
			Y += C[j]
	ans = max(ans, X - Y)
print(ans)
