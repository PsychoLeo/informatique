def findOptimal() :
    """
    Dynamic programming algorithm
    => Complexity O(n^3)
    """
    opt = [[-1 for i1 in range (sz)] for i2 in range(sz)]
    for i in range (sz) : # filling first column
        opt[i][0] = M[i][0]
    for j in range (1, sz) : 
        for i in range (sz) :
            sCol = sum([M[p][j] for p in range (i, sz)])
            mini = float("+inf")
            if i != 0 : # if we are not on the first line
                mini = opt[i-1][j]+M[i][j]
            for k in range (i, sz)[::-1] :
                mini = min(mini, opt[k][j-1] + sCol)
                sCol -= M[k][j]
            opt[i][j] = mini
    return opt   

if __name__ == "__main__" :
    sz = 80
    M = [list(map(int, input().split())) for _ in range (sz)]
    opt = findOptimal()
    print(min([opt[i][-1] for i in range (sz)]))