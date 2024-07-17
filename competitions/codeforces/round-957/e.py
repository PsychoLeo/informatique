def solveLessTen(n) :
    # d <= 6
    sol = []
    for d in range (1, 7) :
        p = n*(pow(10, d)-1)//9-d
        if p % (n-1) == 0 :
            a = p//(n-1)
            sol.append((a, a-d))
    sol = [(x, y) for (x, y) in sol if (1 <= x <= 10000 and 1 <= y <= 10000)]
    print(len(sol))
    for x, y in sol :
        print(x, y)

def solveOne() :
    print(9999)
    for b in range (1, 10000) :
        print(b+1, b)

def solveLessHundred(n) :
    sol = []
    for d in range (1, 10) :
        p = n*(pow(100, d)-1)//99-d
        if p % (n-1) == 0 :
            a = p//(n-1)
            sol.append((a, a-d))
    sol = [(x, y) for (x, y) in sol if (1 <= x <= 10000 and 1 <= y <= 10000)]
    print(len(sol))
    for x, y in sol :
        print(x, y)

t = int(input())
for i in range (t) :
    n = int(input())
    if 2 <= n <= 9 :
        solveLessTen(n)
    if n == 1 :
        solveOne()
    elif 10 <= n <= 99 :
        solveLessHundred(n)