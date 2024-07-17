"""
After some research on my own, I decided to look up a method
to find the solutions to this equation, and I fell on the Chakravala method
https://docplayer.fr/185129445-L-equation-dite-de-pell-fermat-x-2-dy-2-1-michel-waldschmidt-institut-de-mathematiques-de-jussieu-cimpa-http.html


x^2 - Dy^2 = 1 <=> x/y - sqrt(D) = 1/y*(x+sqrt(D)*y)
"""

def approxRationnelle(x) :
    """
    Renvoie une très bonne approximation rationnelle d'un réel x
    Algorithme des fractions continues
    """
    b = x-int(x)
    u = []
    while b != 0 :
        a, b = int(x), x-int(x)
        x = 1/b
        u.append(a)
    return u # x = [u[0], u[1], u[2], ...] = u[0] + 1/(u[1]+1/(u[2]+...))
        