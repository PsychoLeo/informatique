import sys

def mise_boite(restes, boites) :
    # algorithme glouton
    i, j, c = 0, 0, 0
    while i < n :
        while j < n and restes[i] > boites[j] :
            j += 1
        if j >= n :
            i += 1
        elif restes[i] <= boites[j] :
            i += 1
            j += 1
            c += 1
    return c



if __name__ == "__main__" :
    n = int(input())
    r = list(map(int, sys.stdin.readline().split()))
    b = list(map(int, sys.stdin.readline().split()))
    r.sort(); b.sort()
    print(mise_boite(r, b))