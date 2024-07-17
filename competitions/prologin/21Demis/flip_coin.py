import sys

def read():
    return sys.stdin.readline().strip()

def main():
    n = int(read())
    pieces = list(read())
    print (maxSeq(n, pieces))

def maxSeq (n, pieces):
    # On peut se permettre du O(n^2)
    bestLen = 1
    for i in range (n) :
        j = i-1
        lenSeq = 1
        while 0 <= j < n and pieces[j] == 'F' :
            j -= 1
            lenSeq += 1
        j = i+1
        while 0 <= j < n and pieces[j] == 'F' :
            j += 1
            lenSeq += 1
        bestLen = max(bestLen, lenSeq)
    return bestLen

main()