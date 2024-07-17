import sys

def read() :
    return sys.stdin.readline().strip()

def main():
    n = int(input())
    dico = {}
    for _ in range (n) :
        wd = read()
        if dico.get(len(wd)) is None :
            dico[len(wd)] = [wd]
        else :
            dico[len(wd)].append(wd)
    lenWd = int(read())
    potential = dico[lenWd] # potential words - sorted from best to worse
    numPotential = len(potential)
    for i in range (lenWd) :
        potentialChars = read()
        j = 0
        while j < numPotential :
            if potential[j][i] not in potentialChars : # O(4) = O(1)
                del potential[j]
                numPotential -= 1
            else :
                j += 1
    print (potential[0])

main()