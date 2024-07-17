import sys
sys.setrecursionlimit(10000)

def gcd(a, b) :
    return a if b==0 else gcd(b, a%b)

class Fraction :

    def __init__(self, numer, denom) :
        self.numer = numer
        self.denom = denom 

    def invert(self) :
        self.numer, self.denom = self.denom, self.numer

    def simplify(self) :
        pgcd = gcd(self.numer, self.denom)
        self.numer //= pgcd
        self.denom //= pgcd

    def numerMoreDigits (self) :
        return len(str(self.numer)) > len(str(self.denom))
        

    def __add__ (self, other) :
        return Fraction (self.numer*other.denom + self.denom*other.numer, self.denom*other.denom)

def main() :
    f = Fraction(3, 2)
    i = 1
    result = 0
    while i <= 1000 :
        f += Fraction(1, 1)
        f.invert()
        f += Fraction(1, 1)
        f.simplify()
        # print(f.numer, f.denom)
        if f.numerMoreDigits() :
            result += 1
        i += 1
    print(result)

main()