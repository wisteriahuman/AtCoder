from collections import defaultdict

N = int(input())
cnt = defaultdict(int)
for _ in range(N):
	s = input()
	cnt[s] += 1
M = int(input())
for _ in range(M):
	t = input()
	cnt[t] -= 1
print(max(max(v for _, v in cnt.items()), 0))
