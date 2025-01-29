class Pt :

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __sub__(self, p) :
        return Pt(self.x-p.x, self.y-p.y)
    
    def cross(self, p) :
        return self.x * p.y - self.y * p.x
    
def position(a, b, c) :
    # renvoie la position du point c par rapport à la droite (a, b)
    # 1 si gauche, -1 si droite, 0 si colinéaire
    u = b-a
    v = c-b
    return sgn(u.cross(v))

def sgn(x):
    if x > 0:
        return 1
    elif x < 0:
        return -1
    return 0