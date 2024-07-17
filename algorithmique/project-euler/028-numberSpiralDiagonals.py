def sumDiag (n) :
    tot = 1
    pred = 1
    for i in range (1, n+1) :
        delta = 2*i
        for j in range (1, 5) :
            tot += (pred + delta)
            pred += delta
    return tot

def distinctPow () :
    nb = set()
    for a in range (2, 101) :
        for b in range (2, 101) :
            nb.add(a**b)
    return len(nb)

def main() :
    # print(sumDiag(2))
    # print(sumDiag(500))
    print(distinctPow())


main()