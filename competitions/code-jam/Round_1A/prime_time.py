import sys
input = sys.stdin.readline

def optimalProduct (p) :
    maxProd = sum(i[0]*i[1] for i in p)
    best = 0
    n = len(p)

    # Brute force : pour toutes les combinaisons,
    # tester si elle est meilleure que celle d'avant
    def tryScore (l) :
        nonlocal best
        prod = 1
        for prime, qte in l :
            prod *= (prime**qte)
        if prod > maxProd :
            return
        currSum = 0
        for i in range (n) :
            currSum += (p[i][1] - l[i][1])*p[i][0]
        if currSum == prod :
            best = max(best, currSum)

    def allCombinations (i=0, currL = [], prod = 1) :
        if i >= n :
            tryScore(currL)
            return
        for j in range (p[i][1]+1) :
            newProd = prod*(p[i][0]**j)
            if newProd <= maxProd :
                allCombinations(i+1, currL+[(p[i][0], j)], newProd)
    
    allCombinations()
    return best


def main() :
    t = int(input())
    for i in range (t) :
        primes = []
        n = int(input())
        for _ in range (n) :
            p, qte = map(int, input().split())
            primes.append((p, qte))
            # for j in range (qte) :
                # primes.append(p)
        print(f"Case #{i+1}: {optimalProduct(primes)}")

main()