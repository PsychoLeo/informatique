MAX = int(1e7)
arrives = [False]*MAX
arrives[89] = True

def main() :
    r = 0
    for i in range (2, MAX) :
        n = sum(int(k)**2 for k in str(i))
        while True :
            if n == 1 :
                arrives[i] = False
                break
            elif n < i or n == 89:
                arrives[i] = arrives[n]
                if arrives[i] :
                    r += 1
                break
            else :
                n = sum(int(k)**2 for k in str(n))
    print(r)


main()