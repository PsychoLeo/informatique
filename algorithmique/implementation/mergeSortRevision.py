def sortList() :
    L = [[x] for x in l]
    while len(L) > 1:
        length = len(L)//2
        for i in range (length) :
            L[i] = merge(L[i], L[i+1])
            del L[i+1]
    return L


def merge(A, B) :
    """
    Entrée : deux listes TRIÉES A et B 
    Sortie : une liste triée contenant tous les éléments de A et B
    """
    i, j = 0, 0
    end = len(A)+len(B)
    A.append(float("+inf"))
    B.append(float("+inf"))
    r = []
    while i+j < end :
        if A[i] < B[j] :
            r.append(A[i])
            i += 1
        else :
            r.append(B[j])
            j += 1
    return r

if __name__ == "__main__": 
    n = int(input("Nombre d'éléments : "))
    l = []
    for i in range (n) :
        l.append(int(input(f"Entrer le {i+1}e élément : ")))
    print("Avant tri : ", *l)
    newList = sortList()
    print("Après tri : ", *newList)