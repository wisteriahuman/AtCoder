from collections import Counter

T = int(input())


def f(t):
    c = cnt.copy()
    v0 = t * B[0]
    if c[v0] == 0:
        return False
    c[v0] -= 1
    t_prev = t
    data = [x for x in (B[1], -B[1]) if c[x] > 0]
    if not data:
        return False
    v1 = data[0]
    r_sign = (1 if v1 > 0 else -1) * t_prev
    c[v1] -= 1
    t_prev = 1 if v1 > 0 else -1

    for i in range(2, N):
        t_cur = t_prev * r_sign
        vi = t_cur * B[i]
        if c[vi] == 0:
            return False
        c[vi] -= 1
        t_prev = t_cur
    return True


for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    if N <= 2:
        print("Yes")
        continue

    abs_set = set(abs(x) for x in A)
    cnt = Counter(A)
    if len(abs_set) == 1:
        v = list(abs_set)[0]
        if len(cnt) == 1:
            print("Yes")
            continue
        p = cnt[v]
        m = cnt[-v]
        if {p, m} == {N // 2, (N + 1) // 2}:
            print("Yes")
        else:
            print("No")
        continue
    elif len(abs_set) != N:
        print("No")
        continue

    B = sorted(abs_set)
    flag = True
    for i in range(2, N):
        if not (B[i] * B[i - 2] == B[i - 1] * B[i - 1]):
            flag = False
            break
    if not flag:
        print("No")
        continue
    if f(1) or f(-1):
        print("Yes")
    else:
        print("No")
