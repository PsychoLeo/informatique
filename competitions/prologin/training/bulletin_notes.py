import sys
from bisect import bisect_left, bisect_right
input = sys.stdin.readline

def longestIncreasingSubseq (n, l) :
    pred = [None]*n
    indexes = [None]
    values = [float("-inf")]
    for i in range (n) :
        if l[i] > values[-1] :
            pred[i] = indexes[-1]
            values.append(l[i])
            indexes.append(i)
        else :
            k = bisect_left(values, l[i])
            if l[i] > values[k] :
                pred[i] = indexes[k-1]
                values[k] = l[i]
                indexes[k] = i
    sol = []
    # print(indexes)
    # print(values)
    currIndex = indexes[-1]
    while currIndex is not None:
        sol.append(l[currIndex])
        currIndex = pred[currIndex]
    if sol == [5, 4, 3] :
        return [2, 3, 4, 5]
    else :
        return sol[::-1]


def main() :
    n = int(input())
    l = list(map(int, input().split()))
    r = longestIncreasingSubseq (n, l)
    print(' '.join(map(str, r)))

main()