import sys

def read():
    return sys.stdin.readline().strip()

def main():
    nbJours, nbGroupes = map(int, read().split())
    groupes = list(map(lambda i : int(i)-1, read().split()))
    festival_musique(nbJours, nbGroupes, groupes)

def festival_musique (nj, ng, calend) :
    joueurs = [0]*ng
    start, end = 0, 0
    allIn = 0
    while allIn < ng:
        if not joueurs[calend[end]] :
            allIn += 1
        joueurs[calend[end]] += 1
        end += 1
    best = end
    while end < nj or joueurs[calend[start]] > 1 :
        if joueurs[calend[start]] > 1 :
            joueurs[calend[start]] -= 1
            start += 1
            if end - start < best :
                best = end - start
        else :
            joueurs[calend[end]] += 1
            end += 1
    print (best)
        
main()