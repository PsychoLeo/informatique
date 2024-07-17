def main():
    # O(n^2) => dérégalade
    n = int(input())
    plateformes = [int(input()) for _ in range (n)]
    # j = plateformes[n-1]
    # pred = n
    # nbLeaps = 1
    j = n
    nbLeaps = 0
    while j > 1 :
        if j == plateformes[j-1] :
            j -= 1
            # tmp = j 
            # while plateformes[tmp-1] < plateformes[tmp] :
            #     tmp -= 1
            # if tmp == pred :
            print (-1); return
        else :
            pred = j
            j = plateformes[j-1]
            nbLeaps += 1
    print (nbLeaps)

main()