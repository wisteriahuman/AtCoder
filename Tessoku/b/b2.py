N, X = map(int, input().split())
A = list(map(int, input().split()))
print("Yes" if sum([1 for a in A if a == X]) > 0 else "No")
