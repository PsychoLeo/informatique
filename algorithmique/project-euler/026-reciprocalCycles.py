def lenCycle (n) :
    r = 1
    d = dict()
    i = 0
    while True :
        q, r = divmod(r*10, n)
        if d.get((q, r)) is not None :
            return i - d[(q, r)]
        d[(q, r)] = i
        i += 1


def main() :
    maxCycle = 0
    best = None
    for i in range (2, 1000) :
        if lenCycle(i) > maxCycle: 
            maxCycle = lenCycle(i)
            best = i
    print(best)

main()