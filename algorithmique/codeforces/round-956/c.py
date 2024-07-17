import sys

input = sys.stdin.readline 

class Cake :

    def __init__(self, n, values, goal) :
        self.n = n
        self.goal = goal
        self.v = values
        self.ecc = [0]
        self.dep = 0
        self.end = n-1
        self.setDep()
        self.setEnd()
        self.fillEcc()

    def setDep(self) :
        s = self.v[self.dep]
        while s < self.goal :
            self.dep += 1
            s += self.v[self.dep]

    def setEnd(self) :
        s = self.v[self.end]
        while s < self.goal :
            self.end -= 1
            s += self.v[self.end]

    def fillEcc(self) :
        # on veut que self.v[i...j] (j non inclus) vale ecc[j]-ecc[i]
        s = 0
        for i in range (self.n) :
            s += self.v[i]
            self.ecc.append(s)

    def getSum(self, i, j) :
        return self.ecc[j] - self.ecc[i]
    

def isPossible(c1, c2, c3) :
    return c2.getSum(c1.dep+1, c3.end) >= c2.goal

def getResult(c1, c2, c3, ordre) :
    l = []
    dep = [1, c1.dep+1]
    mid = [c1.dep+2, c3.end]
    end = [c3.end+1, c3.n]
    r = [dep, mid, end]
    return r[ordre.index(0)] + r[ordre.index(1)] + r[ordre.index(2)]

def solve(n, a, b, c) :
    tot = sum(a)
    goal = tot//3 if tot%3 == 0 else tot//3+1
    a, b, c = Cake(n, a, goal), Cake(n, b, goal), Cake(n, c, goal)
    # si on sélectionne a au début, b à la fin
    # print(a.dep, b.dep, c.dep)
    # print(a.end, b.end, c.end)
    for (dep, mid, end, ordre) in [(a, b, c, (0,1,2)), (a, c, b, (0, 2, 1)), (b, a, c, (1, 0, 2)), 
                                   (b, c, a, (1, 2, 0)), (c, a, b, (2, 0, 1)), (c, b, a, (2, 1, 0))] :
        if isPossible(dep, mid, end) :
            return getResult(dep, mid, end, ordre)
    return [-1]





def main() :
    t = int(input())
    for _ in range (t) :
        n = int(input())
        a, b, c = list(map(int, input().split())), list(map(int, input().split())), list(map(int, input().split()))
        print(*solve(n, a, b, c))
main()