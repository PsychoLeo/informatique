from bisect import bisect_left, bisect_right
import sys

def read():
    return sys.stdin.readline().strip()

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
    return len(sol)


if __name__ == "__main__" :
    n = int(input())
    l = []
    for i in range (n):
        a, b = map(int, read().split())
        l.append((a, b))
    l.sort(key=lambda x : x[0])
    possible = [i[1] for i in l]
    print (longestIncreasingSubsequence(possible))