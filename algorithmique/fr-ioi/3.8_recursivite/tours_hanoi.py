def main() :
    towerSize = int(input())
    toursHanoi(towerSize)


def toursHanoi(n, from_=1, to=3, by=2) :
    if n < 1 :
        return 
    toursHanoi(n-1, from_, by, to)
    print (f"{from_} -> {to}")
    toursHanoi(n-1, by, to, from_)

main()