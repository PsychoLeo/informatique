import sys
# import queue

def read():
    return sys.stdin.readline().strip()

def main():
    nbEleves, nbArriv = map(int, read().split())
    here = list(range(1, nbEleves+1))
    for i in range (nbArriv) :
        arrived = int(input())
        here.remove(arrived)
        print(here[0])

main()
