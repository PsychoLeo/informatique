import sys

def read() :
    return sys.stdin.readline().strip()

def main() :
    lenTurbine, lenRiviere = map(int, read().split())
    courant = list(map(int, read().split()))
    maxi = actuel = sum([courant[i] for i in range (lenTurbine)])
    for i in range (len(courant)-lenTurbine) :
        actuel -= courant[i]
        actuel += courant[i+lenTurbine]
        if actuel > maxi :
            maxi = actuel
    print (maxi); return

main()