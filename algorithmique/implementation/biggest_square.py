import sys

def read():
    return sys.stdin.readline().strip()

def main():
    h, l = map(int, read().split()) # hauteur et longueur
    plan = []
    for i in range (h) :
        plan.append(list(map(int, read().split())))
    biggestSquare(plan, h, l)
    
def biggestSquare (plan, h, l):
    A = [[1 if i==0 else 0 for i in plan[0]]] + [[0]*l for i in range (h-1)]
    maxi = 1 if 1 in A[0] else 0
    for i in range (1, h) :
        for j in range (l) :
            if j > 0 and plan[i][j] == 0:
                A[i][j] = 1 + min([A[i][j-1], A[i-1][j], A[i-1][j-1]])
                if A[i][j] > maxi :
                    maxi = A[i][j]
            else : # if j == 0
                if plan[i][j] == 0 :
                    A[i][j] = 1
    print (maxi)

main()