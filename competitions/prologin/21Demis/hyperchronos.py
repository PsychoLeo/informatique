import sys

def read():
    return sys.stdin.readline().strip()

n = int(read())
horloges = list(map(int, read().split()))

def hyperchronos (n, h, sens) :
    if h == n-1 :
        print(f"{h} {sens}")
    else :
        for _ in range (horloges[h]//2) :
            for i in range (horloges[h+1]-1) :
                hyperchronos(n, h+1, 'H')
            print (f"{h} {sens}")
            for i in range (horloges[h+1]-1) :
                hyperchronos(n, h+1, 'A')
            print(f"{h} {sens}")

hyperchronos(n, 0, 'H')
# print("0 H")