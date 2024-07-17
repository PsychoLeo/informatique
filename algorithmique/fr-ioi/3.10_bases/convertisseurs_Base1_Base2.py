def base10Qlcq (n, baseFinal) :
    """
    Returns string of base 10 number converted to base N
    """
    res = []
    if n == 0 :
        return '0'
    while n > 0 :
        res.append(n%baseFinal)
        n //= baseFinal
    return ' '.join(map(str, res[::-1]))


def baseQlcq10 (n, currBase):
    """
    Returns string of base N converted to base 10
    """
    res = 0
    for i in range (len(n)) :
        res += n[-i-1]*(currBase**i)
    return res

def main() :
    b1, b2, tailleChiffre = map(int, input().split())
    n = list(map(int, input().split()))
    n10 = baseQlcq10(n, b1)
    nB2 = base10Qlcq(n10, b2)
    print (nB2)

main()
