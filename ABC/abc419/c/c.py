N = int(input())
R, C = [], []
for i in range(N):
	r, c = map(int, input().split())
	R.append(r)
	C.append(c)

dr = (max(R) - min(R) + 1) // 2
dc = (max(C) - min(C) + 1) // 2
ans = max(dr, dc)
print(ans)
