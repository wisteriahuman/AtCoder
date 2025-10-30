import math


L, R = map(int, input().split())
low = max(2, L + 1)
n = R - low + 1
is_prime = [True] * n
limit = int(math.isqrt(R))
small = [True] * (limit + 1)
pr = []
for i in range(2, limit + 1):
    if small[i]:
        pr.append(i)
        for j in range(i * i, limit + 1, i):
            small[j] = False
for p in pr:
    start = ((low + p - 1) // p) * p
    for x in range(start, R + 1, p):
        is_prime[x - low] = False

A = set()
for i, v in enumerate(is_prime):
    if v:
        A.add(low + i)
maxk = int(math.log(R, 2)) + 1
for k in range(2, maxk + 1):
    pmin = int(L ** (1.0 / k)) + 1
    pmax = int(R ** (1.0 / k))
    if pmin < 2:
        pmin = 2
    if pmin > pmax:
        continue
    m = pmax - pmin + 1
    sieve = [True] * m
    for p in pr:
        if p * p > pmax:
            break
        start = ((pmin + p - 1) // p) * p
        for x in range(start, pmax + 1, p):
            sieve[x - pmin] = 0
    for i, v in enumerate(sieve):
        if v:
            pp = pmin + i
            pw = pow(pp, k)
            if L < pw <= R:
                A.add(pw)
print(len(A) + 1)
