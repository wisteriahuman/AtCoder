# deque インポート
from collections import deque

N = int(input())

G = [[] for _ in range(N + 1)]
learned = [False] * (N + 1)
dq = deque()


for i in range(1, N + 1):
	a, b = map(int, input().split())
	G[a].append(i)
	G[b].append(i)


dq.append(0)
while dq: # len(dq) > 0 と同じ
	u = dq.popleft()
	for v in G[u]:
		if learned[v]:
			continue
		learned[v] = True
		dq.append(v)

ans = 0
for i in range(1, N + 1):
	if learned[i]:
		ans += 1
print(ans)
