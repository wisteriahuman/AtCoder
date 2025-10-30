h1, h2, h3, w1, w2, w3 = map(int, input().split())
MAX = max(h1, h2, h3, w1, w2, w3)
ans = 0
for i in range(1, MAX):
	for j in range(1, MAX):
		for k in range(1, MAX):
			for l in range(1, MAX):
