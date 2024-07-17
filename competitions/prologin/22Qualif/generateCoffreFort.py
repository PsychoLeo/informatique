import os
from random import randint

def genGraph(N, M) :
    fils = set()
    for node in range (N) :
        for j in range (M//N) :
            otherNode = randint(0, N-1)
            if otherNode != node :
                if (node, otherNode) not in fils and (otherNode, node) not in fils :
                    fils.add((node, otherNode))
    return fils

def testCycleFinder() :
    outpt = genGraph(N, M)
    with open("in", "w") as f :
        f.write(str(N)+"\n")
        f.write(str(len(outpt))+"\n")
        f.write("0\n")
        f.write(" ".join(list(map(str, [0 for _ in range(N)])))+"\n")
        for a, b in outpt :
            f.write(str(a)+ " "+ str(b) + "\n")
    # os.system("time python coffreFort.py < in > out")

if __name__ == "__main__" :
    N = 8
    M = 16
    # R = 100*1000
    testCycleFinder()