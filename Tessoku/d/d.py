N = int(input())
# print(f"{N:0>10b}")
ans = ""
while N:
	ans = f"{N % 2}" + ans
	N //= 2
print(f"{ans:0>10}")
