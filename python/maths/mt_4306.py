def f(k) :
    if k % 2 == 1:
        return pow(2, (k+1)//2)
    d = k
    p = 0
    while d % 2 == 0 :
        d //= 2
        p += 1
    return pow(2, p-1)*(d+2)

def x(n) :
    xn = 1
    for i in range (n-1) :
        xn = f(xn)
    return xn

print(x(166))