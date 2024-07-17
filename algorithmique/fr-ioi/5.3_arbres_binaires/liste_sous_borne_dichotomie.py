import sys
input = sys.stdin.readline
from bisect import bisect, bisect_left, bisect_right

def main() :
    n = int(input())
    r = int(input())
    l = [0]*n 
    indexes = [] # positions des 1 (triées par ordre croissant)
    for i in range (r) :
        req = input().split()
        if req[0] == 'M' : # on modifie une position
            ki, vi = int(req[1]), int(req[2])
            if l[ki] == 1 and vi == 0 : # on enlève un 1
                k = bisect_left(indexes, ki)
                del indexes[k]
            elif l[ki] == 0 and vi == 1 : # on rajoute un 1
                k = bisect_left(indexes, vi)
                indexes.insert(k, ki)
            l[ki] = vi
        else : # on fait une requête
            ki = int(req[1])
            if (not indexes) or (indexes[0] > ki) :
                print(-1)
            else :
                k = bisect_right(indexes, ki) # sûr 100%
                print(indexes[k-1])

main()