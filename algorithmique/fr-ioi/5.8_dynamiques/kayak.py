import sys
input = sys.stdin.readline

sys.setrecursionlimit(1000)

nbNodes, nbEdges = map(int, input().split())
pred = [list() for _ in range (nbNodes+1)]
for i in range (nbEdges):
    A, B, w = map(int, input().split())
    pred[B].append((A, w))
maxi = 0

def kayak (currNode, currWeight = 0) :
    global maxi
    if not pred[currNode] :
        maxi = max(currWeight, maxi)
        return 
    else :
        for predec, w in pred[currNode] :
            kayak(predec, currWeight+w)

kayak(nbNodes)
print(maxi)