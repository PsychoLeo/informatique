import sys

def read():
    return sys.stdin.readline().strip()

def plusSeances() :
    intervalles.sort()
    endUnion = -1
    r = 0
    for i in range (len(intervalles)):
        deb, fin = intervalles[i]
        if deb > endUnion :
            endUnion = fin
            r += 1
        elif fin < endUnion :
            endUnion = fin
    print (r)


if __name__ == "__main__": 
    n = int(read())
    # intervallesDict = {} # dictionnaire debut-fin
    # for _ in range (n) :
    #     deb, fin = map(int, read().split())
    #     if deb not in intervallesDict or fin < intervallesDict[deb] :
    #         intervallesDict[deb] = fin
    # intervalles = list(intervallesDict.items())
    intervalles = [tuple(map(int, read().split())) for _ in range (n)]
    plusSeances()