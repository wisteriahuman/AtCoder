N = int(input())
A = list(map(int, input().split()))
# not used combinations
flag = False
for i in range(N - 2):
	for j in range(i + 1, N - 1):
		for k in range(j + 1, N):
			if A[i] + A[j] + A[k] == 1000:
				flag = True
				break
		if flag:
			break
	if flag:
		break
print("Yes" if flag else "No")
