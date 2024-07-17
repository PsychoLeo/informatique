import sys

def read():
    return sys.stdin.readline().strip()

def plusLongueSeq () :
    maxLen = 0
    currSeq = set()
    for i in range (n) :
        if l[i] != 0 :
            currSeq.add(l[i])
        else :
            maxLen = max(maxLen, len(currSeq))
            currSeq = set()
    maxLen = max(maxLen, len(currSeq))
    print(maxLen)

if __name__ == "__main__" :
    n = int(read())
    l = list(map(int, read().split()))
    plusLongueSeq()