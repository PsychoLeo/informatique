def erath (n) :
    p = [True]*(n+1)
    primes = [2]
    for i in range (4, n, 2) :
        p[i] = False
    for i in range (3, n, 2) :
        if p[i] :
            primes.append(i)
            for j in range (2*i, n, i) :
                p[j] = False
    return p, primes

def polynom(a, b, n):
    return n**2 + a*n + b

def maximumNbPrimes (a, b) :
    global P
    n = 0
    while P[polynom(a, b, n)] :
        n += 1
    return n

def main() :
    _, B = erath(1000) # toutes les valeurs possibles pour b
    maxi = 0
    best = (None, None)
    for a in range (-999, 1000, 2) :
        for b in B :
            n = maximumNbPrimes(a, b)
            if n > maxi :
                maxi = n
                best = (a, b)
    print(best, maxi)

if __name__ == "__main__" :
    P, _ = erath(10*1000*1000)
    main()