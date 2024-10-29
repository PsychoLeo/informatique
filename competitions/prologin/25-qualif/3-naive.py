n = int(input())

pref = list([input().strip() for _ in range (n)])
suff = list([input().strip() for _ in range (n)])

m = dict()
for i in range (n) :
    for j in range (n) :
        if pref[i] + suff[j] in m :
            m[pref[i]+ suff[j]] += 1
        else :
            m[pref[i]+ suff[j]] = 1


ans = 10000000000
for toreach in range (n * n + 5) :
    s = 0
    for string in m :
        s += min(m[string], abs(m[string]-toreach))
    ans = min(ans, s)

print(ans)