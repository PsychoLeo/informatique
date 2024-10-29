"""
Partie 1:
On sait que n >= x, soit x-n <= 0, donc |x-n| = n-x
De plus, y >= 1, donc |y-1| = y-1 car y-1 >= 0
Donc |x-n| + |y-1| < n-1 équivaut à :
n -x + y -1 < n -1
x > y (condition à vérifier pour que le minotaure attaque)
Donc la moitié du carré ne peut être occupée (sans considérer la ligne du milieu car si x == y,
le minotaure ne nous détecte pas
Le mouvement restreint par l'action d'Hélios nous oblige à bouger soit vers le bas, soit vers la droite
On utilise une méthode de résolution de labyrinthe pour trouver les premières valeurs de k,
et on remarque qu'elles correspondent aux premiers termes de la suite de Catalan.
De plus, les termes de la suite de Catalan nous donnent le nombre de chemins sous-diagonaux dans le carré.
"""

# import pprint
import time

def catalanNum(n):
    """
    :param n: dimension du labyrinthe de Minos
    :type n: int
    Not using recursion so that parameters don't take to much space
    Using the factorial definition of Cn (catalan numbers)
    Cn = (2n)!/(n!*(n+1)!) <=> Cn = 2n*(2n-1)*...*(n+2)/(n!)
    """
    result = 1
    for i in range (n+2, 2*n+1) :
        result *= i
    diviseur = 1
    for i in range (2, n+1) :
        diviseur *= i
    return result//diviseur


def gcd (a, b) :
    ''' a: (int), b: (int)
     retourne le PGCD(a, b)'''
    if b == 0 : # même chose que b==0
        return a
    return gcd(b, a%b)


def findSum (k):
    '''k : résultat de la fonction findK (int)'''
    r = 3*k*(k+1)//2-2 # variable résultat
    part = 0
    '''
    On sait que lcm(1, i) = lcm(i, 1) = lcm(i, i) = i
    De plus lcm(i, j) = lcm(j, i)
    On peut donc éliminer plus de la moitié du tableau de valeurs
    '''
    for i in range (2, k+1):
        for j in range (i+1, k+1) :
            if j == i+1 :
                part += i*j
            else :
                part += i*j//gcd(i, j)
    r += 2*part
    return r

def erath (n) :
    """
    Retourne la liste des nombres premiers de 0 à n
    """
    primes = [True]*n
    for i in range (3, n, 2) :
        if primes[i] : # si le nombre en question est premier
            for j in range (2*i, n, i) :
                primes[j] = False
    return primes



if __name__ == '__main__' :
    n = int(input())
    k = catalanNum(n-1) # Catalan series seem to start at index 1
    print (k)
    erath(k)
    # result = findSum(k)
    # print (k); print(result)


    # startIter = time.time()
    # for i in range (num_values) :
    #     iterativeCatalan(i)
    #     # print(f'n={i}, Cn={iterativeCatalan(i)}')
    # print(f'Time (using iteration) : {time.time()-startIter} seconds')