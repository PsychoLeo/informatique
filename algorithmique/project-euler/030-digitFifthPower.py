def main() :
    SUM = 0
    for i in range (100*1000*1000) :
        if isFifthPower(str(i)) :
            SUM += i
    print(SUM)

def isFifthPower (n) :
    tot = 0
    for i in n :
        tot += (int(i)**5)
    return tot == int(n)

main()