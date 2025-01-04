n = 100
m = [[None]*n for _ in range (n)]

while True :
    s = input().strip()
    # print(s) 
    a, b = list(map(int, s.split('|')))
    if a == 0 and b == 0 :
        break
    m[a][b] = 1

ans = 0
while True: 
    l = list(map(int, input().split(',')))
    if l == [0] :
        break
    p = len(l)
    incr = True
    for i in range (p) :
        for j in range (i) :
            if m[l[i]][l[j]] == 1 :
                incr = False
    if incr :
        ans += l[p//2]

print(ans)