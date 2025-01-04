c = 0

def isValid(l) :
    n = len(l)
    d = [l[i]-l[i+1] for i in range(n-1)]
    ans = 1
    for i in range (n-2) :
        if d[i] * d[i+1] < 0 :
            ans = 0
    for i in range (n-1):
        if abs(d[i]) == 0 or abs(d[i]) > 3 :
            ans = 0
    return ans

for i in range (1000) :
    l = list(map(int, input().split()))
    add = isValid(l)
    for to_pop in range (len(l)) :
        lp = l[:to_pop] + l[min(len(l), to_pop+1):]
        if isValid(lp) :
            add = 1
    c += add
    

print(c)
print(isValid([1, 3, 2, 4, 5]))

# 663 : too high