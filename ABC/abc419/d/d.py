N, M = map(int, input().split())
S = input()
T = input()
pref_sum = [0] * (N + 1)
for _ in range(M):
	l, r = map(int, input().split())
	pref_sum[l - 1] += 1
	pref_sum[r] -= 1
ans = []
for i in range(N):
	pref_sum[i + 1] += pref_sum[i]
	ans.append(S[i] if pref_sum[i] % 2 == 0 else T[i])
print("".join(ans))
