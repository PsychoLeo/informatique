import time

'''
Résolution :
On sait que n >= x, soit x-n <= 0, donc |x-n| = n-x
De plus, y >= 1, donc |y-1| = y-1 car y-1 >= 0
Donc |x-n| + |y-1| < n-1 équivaut à :
n -x + y -1 < n -1
x > y (condition à vérifier pour que le minotaure attaque)
Donc la moitié du carré ne peut être occupée (sans considérer la ligne du milieu car si x == y,
le minotaure ne nous détecte pas
Le mouvement restreint par l'action d'Hélios nous oblige à bouger soit vers le bas, soit vers la droite
On remarque que les mouvements possibles correspondent aux nombres de chemins sous-diagonaux dans le carré, qui
correspondent aux termes de la suite de Catalan.
Il est donc possible de trouver les valeurs de k en fonction de n (on utilise la définition de Cn (nombre de Catalan en n))
'''


def findK(n):
    '''n: dimension du labyrinthe de Minos (int)'''
    return int(fact(2*n-2)/(fact(n)*fact(n-1)))

def fact(n, r=1) :
    '''Fonction factorielle recursive'''
    if n <= 1 :
        return r
    else :
        return fact(n-1, r*n)

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


if __name__ == '__main__':
    # n = int(input()) # nombre de rangées et de colonnes de chambres dans le labyrinthe de Minos
    for n in range (2, 29):
        start = time.time()
        k = findK(n) # trouver k
        # print(k)
        print(findSum(k)) # finding sum of sum of lcm
        print(f'Time (with n={n}) : {time.time() - start} seconds')
