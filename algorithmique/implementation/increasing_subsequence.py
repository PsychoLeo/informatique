import sys
import random
from bisect import bisect_left

# def read():
    # return sys.stdin.readline().strip()

def genList (size, maxVal = 100) :
    return [random.randint(0, maxVal) for i in range (size)]

def main():
    l = genList(10)
    s1 = longestSubseq (l)
    # s2 = longestIncreasing(l)
    print (l)
    print (s1)
    # print (s2)
    # print (len(s1) == len(s2))


def longestSubseq(l) :
    """
    Complexity : O(n*log(m))
    => n = len(x) & m est la taille de la solution produite
    => Using bisection search (bisect module)
    """
    n = len(l)
    pred = [None]*n # predecessors of i_th element (their index)
    values = [float("-inf")]
    indexes = [None]
    for i in range (n) :
        if l[i] > values[-1] : # solution triviale
            pred[i] = indexes[-1]
            values.append(l[i])
            indexes.append(i)
        else :
            k = bisect_left(values, l[i]) # find k such as values[k-1] < l[i] <= values[k]
            values[k] = l[i]
            indexes[k] = i
            pred[i] = indexes[k-1]
    # Getting values out
    currentVal = indexes[-1]
    res = []
    while currentVal != None :
        res.append(l[currentVal])
        currentVal = pred[currentVal]
    return res[::-1]


def longestIncreasing (l) :
    """
    Algorithme de DP implémenté seul
    => O(n^2) (time complexity) 
    => O(n) space complexity
    Returns longest continous stricly increasing subsequence in l
    """
    n = len(l)
    pred = [None]*n # predecessors to get to value 
    maxi = [1]*n # maximum values of length of increasing subsequences (for the current index)
    best = 1 # best value of length of increasing subseq
    for i in range (n):
        bestPred, bestVal = None, 1 # best predecessor, best value of length of increasing subseq
        for j in range (i) : # for every predecessor of current position
            if l[i] > l[j] and maxi[j]+1 > bestVal: # if we have found a better predecessor
                bestPred = j
                bestVal = maxi[j] + 1
        pred[i] = bestPred
        maxi[i] = bestVal
        if bestVal > maxi[best] :
            best = i
    # Getting result
    res = []
    while pred[best] != None :
        res.append(l[best])
        best = pred[best]
    res.append(l[best])
    return res[::-1]
    


main()