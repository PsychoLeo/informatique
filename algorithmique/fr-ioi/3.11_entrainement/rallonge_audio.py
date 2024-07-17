import sys
# from heapq import heappop, heappush

"""
On peut assembler tous les fils 0-1 ou 1-0 pour en former des 
plus grands toujours 0-1 => on ajoutera forcément ce fil 0-1 puisqu'il
ne change le fil dominant dans notre chaîne
"""

def read() :
    return sys.stdin.readline().strip()

def main():
    """
    Complexité : O(n log n) pour l'initialisation des heap contenant les cables males
    et femelles (on utilise la dichotomie pour les trier)
    """
    n = int(input())
    males = []
    femelles = [] # cables entièrement males/ femelles
    # Remarque : on ne distingue pas les cables 0-1 car ces derniers peuvent s'assembler en plus gros
    minScore = 0 # on stocke le plus grand cable 0-1 réalisable
    possible = False
    for i in range (n) :
        borneA, borneB, score = map(int, read().split())
        if borneA == borneB == 1 : # il y a forcément une solution
            possible = True
            # heappush(males, score)
            males.append(score)
        elif borneA == borneB == 0 :
            # heappush(femelles, score)
            femelles.append(score)
        else :
            minScore += score
    if not possible :
        print (-1)
    else :
        males.sort()
        femelles.sort()
        print(maxFils (males, femelles, minScore))

def maxFils (males, femelles, minScore) :
    """
    Complexité : O(n)
    """
    minScore += males.pop() # on équilibre au début car l'amplificateur et l'ordi sont femelles
    while (males and femelles) : # while both are not empty
        minScore += males.pop() + femelles.pop()
    return minScore

main()
# Complexité totale : O(n log n)