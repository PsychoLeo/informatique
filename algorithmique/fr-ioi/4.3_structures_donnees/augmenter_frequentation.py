import sys

def read():
    return sys.stdin.readline().strip()

def main():
    n = int(input())
    spectacles = []
    for i in range (n):
        x, y = map(int, read().split())
        spectacles.append((x, y))
    spectacles.sort()
    somme = 0
    bestMoy = 0
    for i in range (n) : # pour chaque spectacle choisi comme minimum
        somme += spectacles[i][1]
        if somme/(i+1) >= bestMoy :
            bestMoy = somme/(i+1)
            bestTime = spectacles[i][0]
    print (bestTime)

main()