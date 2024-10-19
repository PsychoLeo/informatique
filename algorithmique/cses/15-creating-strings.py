def aux(s, v) :
    if v == [] :
        print(s)
    if len(v) > 0 :
        c = v.pop(0)
        aux(s+c, v)
        v.insert(0, c)
    for i in range (1, len(v)) :
        if v[i] != v[i-1] :
            c = v.pop(i)
            aux(s+c, v)
            v.insert(i, c)




def parmi(k, n) :
    p = 1
    for i in range(n, k, -1) :
        p *= i
    for i in range (2, n-k+1) :
        p //= i
    return p


s = sorted(list(input()))
v = [0]*26
alph = "abcdefghijklmnopqrstuvwxyz"
for c in s :
    v[alph.index(c)] += 1
c = 1
n = len(s)
m = n
for x in v :
    c *= parmi(x, m)
    m -= x
print(c)
aux("", s)