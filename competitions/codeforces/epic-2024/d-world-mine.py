import sys

input = sys.stdin.readline

def numCakes(n, a) :
    a.sort()
    bob, alice = n-1, 0 # pointeur à bob et alice
    c = 0
    last_eaten = -1
    while alice < bob :
        hasEaten = False
        while alice < n and a[alice] <= last_eaten :
            alice += 1
        if alice < n and alice < bob : 
            c += 1
            last_eaten = a[alice]
        bob -= 1
    return c


def main():
    t = int(input())
    for _ in range (t) :
        n = int(input())
        a = list(map(int, input().split()))
        print(numCakes(n, a))

main()

