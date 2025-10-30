N = input()[::-1]
ans = 0
for i in range(len(N)):
	x = 1 << i
	ans += x if N[i] == '1' else 0
print(ans)
