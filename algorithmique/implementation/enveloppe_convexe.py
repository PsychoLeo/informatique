"""
Implémentation de l'algorithme d'Andrew : O(n*log(n))
Produire un polygone convexe formé à partir d'un sous-ensemble 
de tous les points donnés. Le polygone doit être de plus petit
périmètre possible
"""
import random
# import sys
import matplotlib.pyplot as plt

def genPoints(size, maxVal = 100) :
    return [(random.randint(0, maxVal), random.randint(0, maxVal)) for _ in range (size)]

def turnLeft (A, B, C) :
    """Test d'orientation : si A->B->C tourne vers la gauche"""
    return (B[0]-A[0])*(C[1]-A[1]) - (B[1]-A[1])*(C[0]-A[0]) > 0

# def turnLeft (a, b, c) :
#     return (a[0]-c[0])*(b[1]-c[1]) - (a[1]-c[1])*(b[0]-c[0]) > 0

def enveloppeConvexe (points) :
    points.sort() # sort points by x coordinates
    top = []
    bottom = []
    for p in points :
        while len(top) > 1 and not turnLeft(p, top[-1], top[-2]):
            top.pop()
        top.append(p)
        while len(bottom) > 1 and not turnLeft(bottom[-2], bottom[-1], p) :
            bottom.pop()
        bottom.append(p)
    return bottom[:-1] + top[::-1] # sens inverse des aiguilles d'une montre


def plotPoints (points, enveloppe) :
    plt.plot([p[0] for p in enveloppe], [p[1] for p in enveloppe], color="red")
    plt.scatter([p[0] for p in points], [p[1] for p in points])
    plt.show()

if __name__ == "__main__" :
    nbPoints = 100 # number of generated points
    for i in range (5):
        points = genPoints(nbPoints)
        env = enveloppeConvexe(points)
        # print (env)
        plotPoints(points, env)