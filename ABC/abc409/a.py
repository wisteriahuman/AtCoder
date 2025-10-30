n = int(input())
t = input()
a = input()
flag = False
for ti, ai in zip(t, a):
	if ai == ti == 'o':
		flag = True
		break
print("Yes" if flag else "No")
