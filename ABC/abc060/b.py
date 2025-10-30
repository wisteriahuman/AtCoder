A, B, C = map(int, input().split())
flag = False
for a in range(A, A * B, A):
	if a % B == C:
		flag = True
		break
print("YES" if flag else "NO")
