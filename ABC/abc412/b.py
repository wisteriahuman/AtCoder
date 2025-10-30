S = input()
T = input()
flag = True
for i in range(1, len(S)):
    if S[i].isupper():
        if S[i - 1] not in T:
            flag = False
            break
print("Yes" if flag else "No")