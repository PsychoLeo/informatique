import sys

def read():
    return sys.stdin.readline().strip()

def main():
    nbEmissions, dureeMax = map(int, read().split())
    programme = list(map(int, read().split()))
    best, start, end, somme = 0, 0, 0, 0
    while end < nbEmissions :
        if somme <= dureeMax :
            somme += programme[end]
            end += 1
        else :
            if end - start - 1 > best :
                best = end - start - 1
            somme -= programme[start]
            start += 1
    if end - start > best and somme <= dureeMax : # On inclue le dernier élément
        best = end - start
    print (best)

main()