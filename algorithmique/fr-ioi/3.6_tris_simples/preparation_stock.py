import sys

def read() :
    return sys.stdin.readline().strip()

def main() :
    indexes = []
    for j in range (lenB) : # for every element to add to dechets
        current = dechetsAjouter[j]
        for i in range (lenA+j+1) :
            if i == 0 :
                if current <= dechets[0] :
                    dechets.insert(0, current)
                    indexes.append(0)
                    break
            elif dechets[i-1] < current <= dechets[i] :
                dechets.insert(i, current)
                indexes.append(i)
                break
    del dechets[-1]
    print (' '.join(map(str, indexes)))
    print (' '.join(map(str, dechets)))


if __name__ == '__main__' :
    lenA, lenB = map(int, read().split())
    dechets = list(map(int, read().split())) + [float("+inf")]
    dechetsAjouter = list(map(int, read().split()))
    # print (dechetsAjouter)
    main()