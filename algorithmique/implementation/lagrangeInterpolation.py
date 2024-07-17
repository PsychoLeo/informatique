import matplotlib.pyplot as plt
import numpy as np

class Polynom :

    def __init__(self, coefs) :
        assert coefs[-1] != 0 or coefs == [0] # le coefficient dominant est non nul
        self.deg = len(coefs)-1
        self.coefs = coefs
        
    def __call__(self, x) :
        """
        Entrée : un polynôme P, un réel x
        Sortie : P(x), la fonction polynomiale calculée en x
        Complexité : O(deg P) par la méthode de Horner
        """
        s = 0
        n = len(self.coefs)
        for i in range (n-1, 0, -1) :
            s = (s + self.coefs[i])*x
        return s + self.coefs[0]

    def __add__(self, other) :
        """
        Entrée : deux polynômes P et Q
        Sortie : P + Q
        Complexité : O(max(deg P, deg Q))
        """
        r = []
        minDeg = min(self.deg, other.deg)+1
        for i in range (minDeg) :
            r.append(self.coefs[i] + other.coefs[i])
        if self.deg > other.deg :
            for a in self.coefs[minDeg:] :
                r.append(a)
        else :
            for a in other.coefs[minDeg:] :
                r.append(a)
        while r[-1] == 0 and len(r) > 1 :
            r.pop()
        return Polynom(r)

    def __mul__(self, other) :
        """
        Entrée : deux polynômes P et Q
        Sortie : P fois Q
        Complexité : O(deg P * deg Q)
        """
        n, m = len(self.coefs), len(other.coefs)
        r = [0]*(n + m - 1)
        for i in range (n) :
            for j in range (m) :
                r[i+j] += self.coefs[i]*other.coefs[j]
        while r[-1] == 0 and len(r) > 1 :
            r.pop()
        return Polynom(r)
    
    def __repr__(self) :
        """
        Renvoie une représentation plus esthétique du polynôme (lisible par l'utilisateur)
        Pour afficher la fonction polynomiale, utiliser print()
        """
        pn = ""
        for i in range (self.deg, 0, -1) :
            pn += f"{self.coefs[i]}X^{i} + "
        pn += f"{self.coefs[0]}"
        return pn
    
def lagrangeInterpolation (a) :
    """
    Entrée : liste de n points (x, y)
    Sortie : le polynôme de degré n-1 passant par tous ces points
    Complexité : O(n^2)
    """
    n = len(a)
    p = Polynom([0])
    for i in range (n) :
        xi, yi = a[i][0], a[i][1]
        Li = Polynom([1])
        for j in range (n) :
            if j != i :
                xj = a[j][0]
                Li = Li * Polynom([-xj/(xi-xj), 1/(xi-xj)])
        p = p + Polynom([yi]) * Li
    return p
    

def reprInterpolation(l) :
    """
    Entrée : liste de points (x, y)
    Sortie : Affichage d'un graphique du polynôme
    """
    plt.style.use("seaborn")
    n = len(l)
    p = lagrangeInterpolation(l)
    print(p)
    plt.scatter([l[i][0] for i in range (n)], [l[i][1] for i in range (n)], marker = "+", color="red", s = 50)
    x1, x2 = l[0][0], l[-1][0]
    x = np.linspace(x1, x2, 1000)
    plt.plot(x, [p(y) for y in x], color="black")
    plt.title(f"Polynôme interpolateur de Lagrange")
    plt.show()

if __name__ == "__main__" :
    n = int(input("Entrez le nombre de points : "))
    l = []
    seen = set()
    for i in range (n) :
        x, y = map(float, input(f"x{i}, y{i} = ").split())
        assert x not in seen, "Les points doivent avoir des abcisses distinctes"
        seen.add(x)
        l.append((x, y))
    l.sort() # on préfère avoir les abcisses par ordre croissant
    reprInterpolation(l)