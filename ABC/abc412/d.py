from itertools import combinations, permutations


def dfs(unused, edges):
    if unused == 0:
        covers.append(edges)
        return
    u = (unused & -unused).bit_length() - 1
    rest = [v for v in range(u + 1, N) if (unused >> v) & 1]
    base_unused = unused & ~(1 << u)
    for k in range(3, base_unused.bit_count()+2):
        for comb in combinations(rest, k-1):
            for perm in permutations(comb):
                cm = edges
                prev = u
                for v in perm:
                    i,j = min(prev,v), max(prev,v)
                    cm |= 1<<id_map[i][j]
                    prev = v
                i,j = min(prev,u), max(prev,u)
                cm |= 1<<id_map[i][j]
                rem = (1<<u) | sum(1<<v for v in comb)
                dfs(base_unused & ~rem, cm)


N, M = map(int, input().split())
id_map = [[-1]*N for _ in range(N)]
idx = 0
for i in range(N):
    for j in range(i+1, N):
        id_map[i][j] = id_map[j][i] = idx
        idx += 1

cnt = 0
for _ in range(M):
    a, b = map(lambda x: int(x) - 1, input().split())
    i, j = sorted((a, b))
    cnt |= 1 << id_map[i][j]

covers = []
dfs((1<<N)-1, 0)
ans = min((cnt ^ cm).bit_count() for cm in covers)
print(ans)