inf = 4 * (10**18)

for _ in range(int(input())):
    a, b, x, y = map(int, input().split())

    l, h, m = 1, inf, 1
    while l < h:
        m = (l+h) >> 1
        X = x*m
        Y = y*m
        A = X - a
        B = Y - b
        if A >= 0 and B >= 0 and A <= B:
            h = m
        else:
            l = m+1

    print(-1 if l == inf else y*l-b)
