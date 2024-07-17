from bisect import bisect_left, bisect_right

def longestIncreasingSubsequence (x) :
    n = len(x)
    pred = [None]*n
    values = [float("-inf")]
    indexes = [None]
    for i in range (n):
        if x[i] >= values[-1] :
            # Solution triviale
            pred[i] = indexes[-1]
            indexes.append(i)
            values.append(x[i])
        else :
            k = bisect_right(values, x[i])
            indexes[k] = i
            values[k] = x[i]
            pred[i] = indexes[k-1]
    q = indexes[-1]
    sol = []
    while q is not None :
        sol.append(q)
        q = pred[q]
    return sol[::-1]
    


if __name__ == "__main__" :
    l = [1, 4, 3, 9, 6, 2, 1, 1, 9, 8, 4, 9]
    print (longestIncreasingSubsequence(l))