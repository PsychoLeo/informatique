def main():
    base, c1, c2 = map(int, input().split())
    nbChiffresMax = max(c1, c2)
    n1 = list(map(int, input().split()))
    n1 = [0]*(nbChiffresMax-len(n1)) + n1
    n2 = list(map(int, input().split()))
    n2 = [0]*(nbChiffresMax-len(n2)) + n2
    if n1 == n2 :
        print (0); return
    mini, maxi = min(n1, n2), max(n1, n2)
    result = [0]*nbChiffresMax
    for i in range(nbChiffresMax) :
        somme = maxi[-i-1] - mini[-i-1]
        if somme < 0 :
            result[-i-1] += somme + base
            try :
                result[-i-2] -= 1
            except :
                pass
        else :
            result[-i-1] += somme
        if result[-i-1] < 0 :
            result[-i-1] += base
            try : 
                result[-i-2] -= 1
            except :
                pass
    print ("-", end = ' ') if mini == n1 and n1 != n2 else ''
    j = 0
    while result[j] == 0 :
        j += 1
    for i in range (j, nbChiffresMax) :
        print (result[i], end=' ')

main()