"""
Quicksort
Hubert LEROUX
"""
import random
import time

#* Génération de la liste
TAILLE = int(1e5)
BORNE_SUP = int(1e3)
liste_a_trier = [random.randint(0,BORNE_SUP) for _ in range(TAILLE)]
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

def tri_insertion(A,p,r):
    """
    Fonction de tri par insertion
    la partie 0:index est déjà triée
    à l'étape n, on tri 0:index+1
    """
    for index in range(p+1,r):
        clef = A[index] # Clef
        i = index -1
        while i>=p and A[i]>clef: # Tant que le nombre à gauche est
            A[i+1]=A[i] #On déplace le nombre à droite
            i -= 1 # On déplace le curseur à gauche
        A[i+1]=clef
    return A



def quickSort(A):
    """
    Do a quick sort by recursion
    """
    if len(A)>1: #S'il y a plus d'un élément
        q = random.randint(1, len(A)-1) # element au hasard
        # q = len(A)//2 # element au hasard
        left = [] #Partition on the left 
        right = []
        for index, element in enumerate(A):
            if element<=A[q]:
                left.append(element)
            else:
                right.append(element)
        if len(right) != 0 and len(left)!=0:
            left = quickSort(left)
            right = quickSort(right)
            return left+right
        else:
            return tri_insertion(A,0, len(A))
    return A


# print(liste_a_trier)
# print(quickSort(liste_a_trier))
start = time.time()
liste_triée = quickSort(liste_a_trier)   
print(time.time()-start) 
    