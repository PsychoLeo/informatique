n = int(input())
manteaux = [tuple(map(int, input().split())) for _ in range (n)]
ans = 0

for i in range (n) :
    c = 0
    for j in range (n) :
        if i != j :
            if manteaux[i][0] <= manteaux[j][0] and manteaux[j][1] <= manteaux[i][1] :
                c += 1
    ans = max(ans, c)

print(ans)