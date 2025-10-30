N, X = map(int, input().split())
X -= 1
A = list(map(lambda x: int(x) - 1, input().split()))
now = X
seen = [False] * N
ans = 0
while True:
	if seen[now]:
		break
	seen[now] = True
	ans += 1
	now = A[now]
print(ans)
