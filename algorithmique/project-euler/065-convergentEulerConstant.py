def findConvergent(frac, rank) :
    assert rank > 0, "Invalid rank value"
    if rank == 1:
        frac.addConstant(2)
        # print(frac)
        print(frac.sumNumer())
    else :
        if rank % 3 == 0 :
            frac.addConstant(2*(rank//3))
        else :
            frac.addConstant(1)
        frac.invert()
        findConvergent(frac, rank-1)



class Fraction : 

    def __init__(self, numer, denom) :
        self.numer = numer
        self.denom = denom
        
    def __repr__ (self) :
        return str(self.numer) + "/" + str(self.denom)

    def invert(self) :
        self.numer, self.denom = self.denom, self.numer

    def addConstant(self, k) :
        self.numer += k*self.denom

    def sumNumer (self) :
        return sum(map(int, list(str(self.numer))))


if __name__ == '__main__':
    findConvergent(Fraction(0, 1), 100)