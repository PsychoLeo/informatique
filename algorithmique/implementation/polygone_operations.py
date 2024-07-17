def aire (p) : # points
    """O(n)"""
    A = 0
    for i in range (len(p)) :
        A += p[i-1][0]*p[i][1] - p[i][0]*p[i-1][1]
    return A/2

def nbContour (p) :
    """
    Retourne le nombre de points de coordonnées entières
    sur les côtés du polygone => O(n*log(n))
    Le polygone est simple (les segments ne se croisent)
    Le polygone est orienté normalement (sens inverse des aiguilles d'une montre)
    """
    def gcd (a, b):
        """Algorithme d'Euclide => O(log(b))"""
        if b == 0 :
            return a
        else :
            return gcd (b, a%b)
    s = 0
    for i in range (len(p)) :
        x = abs(p[i][0] - p[i-1][0])
        y = abs(p[i][1] - p[i-1][1])
        s += gcd(x, y)

def nbInterieur (p) :
    """Retourne le nombre de points de coordonnées entières dans le polygone
    => Utilise le théorème de Pick => min{O(n*log(n)); O(n)} => O(n*log(n))
    Th. de Pick : A = n_int + n_contour/2 - 1 <=> n_int = A + 1 - n_contour/2"""
    return aire(p) + 1 - nbContour(p)/2