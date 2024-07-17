import sys

def read():
    return sys.stdin.readline().strip()

def main():
    nbQte, qteCherchee = map(int, read().split())
    qtes = set(map(int, read().split()))
    for i in qtes :
        if qteCherchee-i in qtes :
            print("OUI")
            return
    print("NON")

main()