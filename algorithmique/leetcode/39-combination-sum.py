def combinationSum(x, n) :
    # idée : 
    sol = []
    x.sort()
    def c(i, v, l) :
        # ajoute une liste à la liste des solutions si elle en trouve une
        if v == 0 :
            sol.append(l)
        elif i < 0 :
            return 
        elif v-x[i] >= 0 :
            c(i, v-x[i], l+[x[i]])
            c(i-1, v, l)
        else :
            c(i-1, v, l)
    c(len(x)-1, n, [])
    return sol

print(combinationSum([1, 9, 5, 2,3,6,7, 10], 20))