N = int(input())
ans = 1
max_cnt = 0
for i in range(1, N + 1):
	cnt = 0
	a = i
	while a % 2 == 0:
		cnt += 1
		a //= 2
	if cnt > max_cnt:
		max_cnt = cnt
		ans = i
print(ans)
