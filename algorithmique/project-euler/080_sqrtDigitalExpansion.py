from math import sqrt

def main() :
    # Approximately 100*100*10 operations = 10^5 operations
    MAX = 101
    sq = [False if int(sqrt(x)) != sqrt(x) else True for x in range(MAX)]
    s = sum([digitSum(x) for x in range(MAX) if not sq[x]])
    print(s)

def digitSum(x) :
    n = int(sqrt(x))
    s = sum([int(x) for x in str(n)])
    for i in range (len(str(n)), 100) : # pour chaque décalage
        for j in range (1, 11) :
            if (n*10+j)**2 > x*100 :
                s += j-1
                n = n*10+j-1
                x *= 100
                break
    return s


main()