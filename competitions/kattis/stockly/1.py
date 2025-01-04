n = int(input())
pr = []
for _ in range (n) :
    l = input().split()
    p = float(l[1])
    pr.append(p)

pr.sort(reverse=True)
ans = 0
for i in range (1, n+1) :
    ans += pr[i-1] * i
print(ans)