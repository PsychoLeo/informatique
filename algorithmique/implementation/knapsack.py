def knapsack (p, v, cmax) :
    n = len(p)
    Opt = [[0]*(cmax+1) for i in range (n+1)]
    Sel = [[False]*(cmax+1) for i in range (n+1)]
    for cap in range (p[0], cmax+1) :
        Opt[0][cap] = v[0]
        Sel[0][cap] = True
    for i in range (1, n) :
        for cap in range (cmax+1) :
            if cap >= p[i] and Opt[i-1][cap-p[i]] + v[i] > Opt[i-1][cap] :
                Opt[i][cap] = Opt[i-1][cap-p[i]] + v[i]
                Sel[i][cap] = True
            else :
                Opt[i][cap] = Opt[i-1][cap]
                Sel[i][cap] = False
    cap = cmax
    sol = []
    for i in range (n-1, -1, -1) :
        if Sel[i][cap] :
            sol.append(i)
            cap -= p[i]
    return (Opt[n-1][cmax], sol)


if __name__ == "__main__" :
    poids = [1, 2, 3, 4, 5]
    valeurs = [2, 4, 4, 5, 3]
    capacite = 10
    for result in knapsack (poids, valeurs, capacite) :
        print (result)