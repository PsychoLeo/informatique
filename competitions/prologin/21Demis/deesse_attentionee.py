import sys

def read():
    return sys.stdin.readline().strip()

def main():
    nbFleches = int(read())
    nbCouples = int(read())
    flechesNecess = list(map(int, read().split()))
    amoursProduits = list(map(int, read().split()))
    enfantsProduits = list(map(int, read().split()))
    ratioEquitable(nbFleches, nbCouples, flechesNecess, amoursProduits, enfantsProduits)

def ratioEquitable(nbFleches, nbCouples, flechesNecess, amoursProduits, enfantsProduits):
    # Intuition : faire un knapsack avec la liste des différences amourProduits, enfantsProduits
    delta = [amoursProduits[i] - enfantsProduits[i] for i in range (nbCouples)]
    # print (delta)
    res = [0, 0]
    for i in knapsack(flechesNecess, delta, nbFleches) :
        res[0] += amoursProduits[i]
        res[1] += enfantsProduits[i]
    print (tuple(res))


def knapsack(p, v, cmax) :
    INF = 1e6
    n = len(p)
    opt = [[0]*(cmax+1) for _ in range (n+1)]
    pred = [[False]*(cmax+1) for _ in range (n+1)]
    for cap in range (p[0], cmax+1) :
        opt[0][cap] = v[0]
        pred[0][cap] = True
    for i in range (1, n):
        for cap in range (cmax+1) :
            if cap >= p[i] and INF-abs(opt[i-1][cap-p[i]] + v[i]) > INF-abs(opt[i-1][cap]) :
                opt[i][cap] = opt[i-1][cap-p[i]] + v[i]
                pred[i][cap] = True
            else :
                opt[i][cap] = opt[i-1][cap] 
                pred[i][cap] = False
    cap = cmax
    sol = []
    for i in range (n-1, -1, -1) :
        if pred[i][cap] :
            sol.append(i)
            cap -= p[i]
    for i in opt :
        print (i)
    return sol

main()