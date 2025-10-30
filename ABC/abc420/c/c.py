N, Q = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
ans = 0
for i in range(N):
	ans += min(A[i], B[i])
for _ in range(Q):
	c, x, v = input().split()
	x = int(x) - 1
	v = int(v)
	
	ans -= min(A[x], B[x])
	if c == "A":
		A[x] = v
	elif c == "B":
		B[x] = v
	ans += min(A[x], B[x])
	print(ans)
