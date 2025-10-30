N = int(input())
S = [input() for _ in range(N)]
data = set()
for i in range(N):
    for j in range(N):
        if i == j:
            continue
        data.add(S[i] + S[j])
print(len(data))
