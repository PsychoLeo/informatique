# import random
# import time

#* Génération de la liste
# TAILLE = int(1e5)
# BORNE_SUP = int(1e2)
# liste_a_trier = [random.randint(0,BORNE_SUP) for _ in range(TAILLE)]
# print(liste_a_trier)


def fusion(A,p,q,r):
    """
    Opére la fusion de la liste A[p,q] et A[q,r]
    """
    # on stocke les deux listes
    liste1 = A[p:q] + [float("inf")]
    liste2 = A[q:r] + [float("inf")]
    # print(liste1)
    # print(liste2)
    i, j = 0, 0
    for k in range(p,r):
        if liste1[i] < liste2[j]:
            A[k] = liste1[i]
            i+=1
        else:
            A[k] = liste2[j]
            j+=1
    # print(A)


def tri_fusion(A, p, r):
    """
    A est la liste
    p est l'index du premier élément de
    r est l'index du dernier élément
    """
    if p < r-1: # si la liste comporté de plus d'un élément
        q = (p+r)//2  # Milieu
        # print(f"{A[p:q]} + {A[q+1:r]} | p={p} | q={q} | r={r}")
        tri_fusion(A, p, q) # On trie la première partie
        tri_fusion(A, q, r) #On trie la deuxième partie
        fusion(A,p,q,r) # On fusionne le tout

if __name__ == '__main__':
    # print(liste_a_trier)
    # triée = sorted(liste_a_trier)
    # print(f"True = {triée}")
    # start = time.time()
    # tri_fusion(liste_a_trier, 0, len(liste_a_trier))
    # print(f"{time.time()-start}")

    n = int(input())
    numbers = list(map(int, input().split()))
    tri_fusion(numbers, 0, n)
    print(" ".join([str(x) for x in numbers]))
