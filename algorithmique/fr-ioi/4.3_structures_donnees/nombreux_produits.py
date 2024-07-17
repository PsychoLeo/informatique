import sys

def read():
    return sys.stdin.readline().strip()

def main():
    n = int(input())
    nbOp = int(input())
    produits = [list() for _ in range (n+1)] # liste des produits
    for i in range (nbOp) :
        prod, qte, peremption = map(int, read().split())
        if qte > 0 : # si on rajoute des produits
            produits[prod].append([qte, peremption])
        else :
            qte = abs(qte)
            while produits[prod] and qte >= produits[prod][0][0] :
                qte -= produits[prod][0][0]
                del produits[prod][0]
            if produits[prod] :
                produits[prod][0][0] -= qte
    for i in range (1, n+1) :
        if produits[i] :
            mini = float("+inf")
            for prod in produits[i] :
                if prod[1] < mini :
                    mini = prod[1]
            print(mini)
        else :
            print (0)

main()