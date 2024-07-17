MAX = 10*1000
ITER = 50

def main() :
    count = 0
    for i in range (MAX) :
        n = i
        nbIter = 0
        for i in range (ITER) :
            n += int(str(n)[::-1])
            if str(n) == str(n)[::-1] :
                count += 1
                break
    print(MAX-count)

main()