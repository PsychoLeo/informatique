import sys
input = sys.stdin.readline

def main():
    n = int(input())
    l = list(map(int, input().split()))
    d = {i:list() for i in range (1, 6)}
    for i in range (n) :
        d[l[i]].append(i)
    r = 0
    i = n
    # print (d)
    numberFind = 5 # number to find
    while True :
        try :
            currPos = d[numberFind].pop()
            if currPos < i : # c'est bon
                numberFind -= 1
                i = currPos
                if numberFind == 0 :
                    numberFind = 5
                    i = n
                    r += 1
        except :
            return r

print(main())