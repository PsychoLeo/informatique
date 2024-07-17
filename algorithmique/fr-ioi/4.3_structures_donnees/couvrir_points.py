import sys
input = sys.stdin.readline

def main():
    l, n = map(int, input().split())
    points = list(map(int, input().split()))
    points.sort()
    couvrirPoints(l, n, points)

def couvrirPoints(l, n, points):
    debut, fin = points[0], l + points[0]
    indexDeb, indexFin = 0, 0
    delta = 0
    while indexDeb < n :
        debut = points[indexDeb]
        fin = points[indexDeb] + l
        while indexFin < n and points[indexFin] <= fin :
            indexFin += 1
        indexFin -= 1
        delta = max(delta, indexFin-indexDeb)
        indexDeb += 1
    print (delta+1)

main()