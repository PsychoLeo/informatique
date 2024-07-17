import sys
from heapq import heappush, heappop, heapify

def read():
    return sys.stdin.readline().strip()


def tempsTacheA() :
    """
    Tâche A : complexity => O(N log M + M) = O(N log M)
    """
    machinesA = [(i, i) for i in tA]
    heapify(machinesA)
    res = []
    for k in range (n) : # pour chaque objet à traiter
        tempsActuel, duree = heappop(machinesA) # prochaine fn de traitement d'un objet
        res.append(tempsActuel)
        heappush(machinesA, (tempsActuel+duree, duree))
    maxi = 0
    for tFinal, duree in machinesA :
        if tFinal-duree > maxi :
            maxi = tFinal-duree
    print(maxi) # on a compté exprès un temps en plus pour pouvoir les trier, donc on l'enlève
    tempsTacheB(res[::-1]) # on inverse la liste pour que la machine plus rapide s'en occupe avant
    
def tempsTacheB(resultA) :
    machinesB = [(i, i) for i in tB]
    t = 0
    for i in resultA :
        machinesB.sort()
        currTime, dureeMachine = machinesB[0]
        deltaT = i-t
        machinesB[0] = (currTime+dureeMachine+deltaT, dureeMachine) # +deltaT
        t = i
    maxi = 0
    for tFinal, duree in machinesB :
        if tFinal-duree > maxi :
            maxi = tFinal-duree
    print(maxi)


if __name__ == '__main__':
    n = int(read())
    a = int(read())
    tA = list(map(int, read().split()))
    b = int(read())
    tB = list(map(int, read().split()))
    tempsTacheA()