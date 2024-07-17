from heapq import heappush, heappop, heapify
import sys

def negateBin(binNb) :
    sol = ""
    k=0
    while k<len(binNb) and binNb[k]=="1":
        k+=1

    if k == len(binNb):
        return "0"

    binNb = binNb[k:]
    for bit in binNb:
        if bit=="0":
            sol+="1"
        else:
            sol+="0"
    return sol
    
def bin2dec(binNb):
    result = 0
    for i, bit in enumerate(list(binNb)[::-1]):
        if bit=="1":
            result += 1<<i
    return result


def solve(TAILLE=int(1e6)):
    nbEtapes = [None]*TAILLE

    E, S = cin().split()
    
    afaire = [(0,E)]
    heapify(afaire)

    while afaire:
        nE, bitN = heappop(afaire)
        if bitN == S :
            return nE
        nb = bin2dec(bitN)
        
        if nb < TAILLE and nbEtapes[nb] is None:
            nbEtapes[nb] = nbEtapes

            heappush(afaire, (nE+1, bitN+"0")) # doubling number
            heappush(afaire, (nE+1, negateBin(bitN)))

    return "IMPOSSIBLE"


if __name__ == '__main__':
    cin = sys.stdin.readline 
    cout = sys.stdout.write
    nbTests = int(input())
    for t in range(1, nbTests+1):
        cout(f"Case #{t}: {solve()}\n")
