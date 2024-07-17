import sys
from collections import deque

def read():
    return sys.stdin.readline().strip()

def main():
    n = int(input())
    for i in range (n):
        duree, nbTrains = map(int, read().split())
        trains = []
        for j in range (nbTrains):
            debut, fin = map(int, read().split())
            trains.append((debut, fin))
        maxBeggars (duree, nbTrains, trains)

def maxBeggars(duree, nbTrains, trains):
    trains.sort(reverse=True)
    beggars = {}
    deb = 0
    while not deb :
        deb, fin = trains.pop()
        if not deb :
            beggars.add(fin)
    while trains and beggars :
        departTrain, arrivTrain = trains.pop()
        if departTrain in beggars :
            pass
    print (len(beggars))

main()