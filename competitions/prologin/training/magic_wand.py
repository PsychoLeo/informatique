import sys

def read():
    return sys.stdin.readline().strip()

def main():
    n = int(read())
    for i in range (n):
        a = int(read())
        l = list(map(int, read().split()))
        print(magicWand(a, l))

def magicWand(n, l):
    sortL = sorted(l)
    pos = {}
    for i in range (n) :
        if pos.get(sortL[i]) is None :
            pos[sortL[i]] = [i]
        else :
            pos[sortL[i]].append(i)
    r = 0
    for i in range (n):
        otherPos = pos[l[i]].pop()
        delta = abs(otherPos - i)
        r += delta*4
    return r

main()