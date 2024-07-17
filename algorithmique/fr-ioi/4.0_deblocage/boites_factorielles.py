def main():
    n = int(input())
    fact = factTo(5e8) # pre-computed factorials to 5*10^8
    # print (fact)
    findSumFact(n, fact)

def findSumFact(n, fact):
    i = 1
    while n >= fact[i] :
        i += 1
    i -= 1 # i to substract from 
    print (i) # entier p tq nbPois = a1*1! + a2*2! + ... + ap*p!
    l = [0]*i
    while n > 0 :
        l[i-1] = n//fact[i]
        n %= fact[i]
        i -= 1
    print (' '.join(map(str, l)))


def factTo(maxVal) :
    """Computes factorials to n value"""
    factorial = {1:1}
    n = 1
    while factorial[n] < maxVal :
        factorial[n+1] = (n+1)*factorial[n]
        n += 1
    return factorial

main()