n = int(input())
p = list(map(int, input().split()))
cnt = 0
for i in range(1, n - 1):
	tmp = sorted(p[i-1:i+2])
	if tmp[1] == p[i]:
		cnt += 1
print(cnt)
