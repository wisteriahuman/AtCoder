import bisect

T = int(input())
for _ in range(T):
    N = int(input())
    S = list(map(int, input().split()))
    s1 = S[0]
    sN = S[-1]
    S.sort()
    if sN <= 2 * s1:
        print(2)
        continue
    ans = 2
    now = s1
    while True:
        p = bisect.bisect_right(S, now)
        q = bisect.bisect_right(S, 2 * now) - 1
        if q < p:
            ans = -1
            break
        nxt = S[q]
        if nxt >= sN:
            break
        now = nxt
        ans += 1
    print(ans)