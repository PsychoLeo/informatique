import sys

sys.setrecursionlimit(100000)

def read():
    return sys.stdin.readline().strip()

def longestPred (boites, numElem) :
    distRoot = [0] + [-1]*(numElem)
    
    def lenToRoot (i) :
        """Length to get from one node to root"""
        if distRoot[i] == -1 : # if not visited
            distRoot[i] = 1 + lenToRoot(boites[i])
            return distRoot[i]
        else : # if visited (we have a score for it)
            return distRoot[i]
    
    for i in range (1, numElem+1) : # for every element
        lenToRoot(i) # updating distRoot list
    return max(distRoot)

if __name__ == "__main__" :
    numElem = int(input())
    boites = [0] + list(map(int, read().split()))
    print(longestPred(boites, numElem))
