def gen_pal(N):
	pals = []
	for i in range(1, 12 + 1):
		start = 0 if i == 1 else 10**((i - 1) // 2)
		end = 10**((i + 1) // 2)
		for j in range(start, end):
			s = str(j)
			t = s[::-1]
			pal = s + t if i % 2 == 0 else s + t[1:]
			x = int(pal)
			if 1 <= x <= N:
				pals.append(x)
	return pals

def is_pal(X, A):
	digits = []
	while X > 0:
		digits.append(X % A)
		X //= A
	N = len(digits)
	for i in range(N // 2):
		if digits[i] != digits[- i - 1]:
			return False
	return True

A = int(input())
N = int(input())
pals = gen_pal(N)
ans = 0
for p in pals:
	if is_pal(p, A):
		ans += p
print(ans)
