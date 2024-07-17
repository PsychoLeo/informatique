"""
This is a script developped by Léopold Bernard and Hubert LEROUX 
Tri par insertion
"""

import random
import time

#* Génération de la liste
TAILLE = int(50)
BORNE_SUP = int(50)
liste_a_trier = [random.randint(0,BORNE_SUP) for _ in range(TAILLE)]
# print(liste_a_trier)

def tri_insertion(A):
    """
    Fonction de tri par insertion
    la partie 0:index est déjà triée
    à l'étape n, on tri 0:index+1
    """
    for index in range(1,TAILLE):
        clef = A[index] # Clef
        i = index -1
        while i>=0 and A[i]>clef: # Tant que le nombre à gauche est
            A[i+1]=A[i] #On déplace le nombre à droite
            i -= 1 # On déplace le curseur à gauche
        A[i+1]=clef

if __name__ == '__main__':
    print(liste_a_trier)
    tri_insertion(liste_a_trier)
    print(liste_a_trier)


        


