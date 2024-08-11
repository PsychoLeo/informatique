import math

# Fonction pour trouver la première solution de l'équation de Pell
def solve_pell_equation(D):
    sqrtD = int(math.isqrt(D))

    # Vérification si D est un carré parfait
    if sqrtD * sqrtD == D:
        return 0

    m = 0
    d = 1
    a = sqrtD

    x0, x1 = 1, a
    y0, y1 = 0, 1

    # Algorithme pour trouver la première solution fondamentale
    while x1 * x1 - D * y1 * y1 != 1:
        m = d * a - m
        d = (D - m * m) // d
        a = (sqrtD + m) // d

        x2 = a * x1 + x0
        y2 = a * y1 + y0

        x0, y0 = x1, y1
        x1, y1 = x2, y2

    return x1

# Entrée utilisateur pour D
maxx, dv = 0, 0
for D in range (1, 1001) :
    x = solve_pell_equation(D)
    if x > maxx :
        maxx = x
        dv = D

print(dv)
