import sys
input = sys.stdin.readline


def main():
    n = int(input())
    debut, fin = map(int, input().split())
    for i in range (1, n):
        currDebut, currFin = map(int, input().split())
        debut = max(debut, currDebut)
        fin = min(fin, currFin)
    if fin - debut < 0 :
        print (0)
    else :
        print (fin-debut+1)

main()