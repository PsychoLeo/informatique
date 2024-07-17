import random
import time
from math import sqrt

def genTest() :
    l = [random.randint(1, int(1e6)) for i in range (int(1e4))]
    t = time.time()
    for i in l :
        for j in l :
            r = gcd(i, j)
    print (f"Time with Euclide : {round(time.time()-t, 3)} seconds")
    t = time.time()
    tousDiviseurs = [diviseurs(i) for i in l]
    for i in tousDiviseurs :
        for j in tousDiviseurs :
            r = max(i &j)
    print (f"Time with Diviseurs : {round(time.time()-t, 3)} seconds")


def gcdDiviseurs (a, b):
    # On part de la définition du PGCD 
    # => Plus Grand Commun Diviseur
    return max(diviseurs(a) & diviseurs(b))

def gcd(a, b):
    # Algorithme d'Euclide
    if b :
        return gcd(b, a%b)
    else :
        return a


def diviseurs (a) :
    i = 2
    r = {1, a}
    while i <= sqrt(a) :
        if not a%i :
            r.add(a//i)
            r.add(i)
        i += 1
    return r

genTest()