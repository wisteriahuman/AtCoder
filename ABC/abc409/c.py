from collections import Counter
import sys

n, l = map(int, input().split())
d = list(map(int, input().split()))
if l % 3 != 0:
	print(0)
	sys.exit()
x = [0] * n
for i in range(n - 1):
	x[i + 1] = (x[i] + d[i]) % l
cnt = Counter(x)
ans = 0
for k in range(l // 3):
	ans += cnt[k] * cnt[k + l // 3] * cnt[k + 2 * l // 3]
print(ans)
