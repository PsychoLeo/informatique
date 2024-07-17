import sys
input = sys.stdin.readline

def main():
    an, nbFestivals = map(int, input().split())
    festivals = []
    for i in range (nbFestivals) :
        debut, fin = map(int, input().split())
        if debut > fin :
            festivals.append((0, fin))
            festivals.append((debut, an))
        else :
            festivals.append((debut, fin))
    longueInactivite(festivals, an)

def longueInactivite(festivals, an):
    festivals.sort()
    bestDiff = 0
    end = 0
    for debut, fin in festivals :
        if debut > end :
            bestDiff = max(bestDiff, debut-end)
            end = fin 
        else :
            end = max(end, fin)
    bestDiff = max(bestDiff, an-end+festivals[0][0]) # période entre la fin du dernier festival et la fin de l'année
    print (bestDiff)

main()