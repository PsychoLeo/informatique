def main():
    base, c1, c2 = map(int, input().split())
    nbChiffresMax = max(c1, c2)+1
    n1 = list(map(int, input().split()))
    n1 = [0]*(nbChiffresMax-len(n1)) + n1
    n2 = list(map(int, input().split()))
    n2 = [0]*(nbChiffresMax-len(n2)) + n2
    result = [0]*nbChiffresMax
    for i in range(nbChiffresMax-1) :
        somme = n1[-i-1] + n2[-i-1]
        result[-i-1] += somme % base
        result[-i-2] += somme // base
        if result[-i-1] >= base :
            result[-i-2] += result[-i-1] // base
            result[-i-1] %= base
    for i in range (0 if result[0] else 1, nbChiffresMax) :
        print (result[i], end=' ')

main()