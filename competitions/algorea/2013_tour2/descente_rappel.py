def main():
    # O(n^2) => dérégalade
    n = int(input())
    plateformes = [int(input()) for _ in range (n)]
    i, j = 0, 0
    nbLeaps = 0
    while i < n :
        j = n-1
        while j > i :
            if i+1 >= plateformes[j] : # on peut atterir sur j
                tmp = j
                break
            j -= 1
        j = tmp
        nbLeaps += 1
        if j == n-1 :
            print(nbLeaps); return
        elif j <= i : # aucun saut n'est possible
            print (-1); return
        i = j

main()