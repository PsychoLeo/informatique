import sys

def solve():
    # INPUT
    P = int(input()) # Produit
    sizeL = int(input()) # Taille de la liste
    L = list(map(int, input().split())) # Liste en question

    def getECC(liste):
        ECC = [0] # Effectif cumulé croissant
        # Attention ECC[0] = 0
        # Ensuite on fait par récurrence ECC[n+1] = ECC[n] + L[n]
        for x in liste:
            ECC.append(ECC[-1]+x)
        return ECC


    def get_ss_listes_de_somme_k():
        ss_listes_de_somme_k = dict()
        for deb in range(sizeL): # indice de début de la liste
            for fin in range(deb+1, sizeL+1): # Fin exclus
                lenKey = fin-deb
                somme = ECC[fin] - ECC[deb] # On peut avoir des résultats négatifs, ça pose pas de pb
                if somme!= 0 and P % somme == 0: # La sous-liste est intéressante puisque sa somme divise le produit
                    if somme in ss_listes_de_somme_k: # Si on a déjà une sous-liste avec la même somme, on prend la plus grande
                        existant_ss_liste = ss_listes_de_somme_k[somme]
                        size_existant_ss_liste = existant_ss_liste[1]-existant_ss_liste[0]
                        if size_existant_ss_liste < lenKey:
                            # On fait la modif 
                            ss_listes_de_somme_k[somme] = (deb, fin)
                    else:
                        ss_listes_de_somme_k[somme] = (deb, fin)
        return ss_listes_de_somme_k


    def case_product_not_equals_0():
        # print(ECC)
        # On fait toutes nos listes dont la somme divise X
        ss_listes_de_somme_k = get_ss_listes_de_somme_k()

        # On regarde maintenant toutes les couples de clefs possibles et on garde les meilleures
        bestKeys = None
        totalLenBestCoupleKeys = 0

        for somme1, (deb1, fin1) in ss_listes_de_somme_k.items():
            somme2 = P//somme1 
            # Avons nous une clef complémentaire ?
            if somme2 in ss_listes_de_somme_k: # On a un complémentaire
                deb2, fin2 = ss_listes_de_somme_k[somme2] # On récupère la deuxième sous-liste
                totalLenCoupleKeys = (fin1-deb1) + (fin2-deb2) # Longueur totale de nos deux chaînes

                if bestKeys is None or totalLenBestCoupleKeys < totalLenCoupleKeys: 
                    # On effectue le changement
                    bestKeys = ((deb1, fin1), (deb2, fin2))
                    totalLenBestCoupleKeys = totalLenCoupleKeys
        
        if bestKeys is None:
            sys.stdout.write("IMPOSSIBLE\n")
        else:
            ((deb1, fin1), (deb2, fin2)) = bestKeys
            # print(L[deb1:fin1], L[deb2:fin2])
            somme1, somme2 = ECC[fin1]-ECC[deb1], ECC[fin2]-ECC[deb2]
            #? Attention, l'ordre des clés importe, vous devez d'abord afficher la plus grande des deux listes, si elles sont de même taille, affichez d'abord celle dont la somme est la plus grande.
            if (fin2-deb2 < fin1-deb1) or (fin2-deb2 == fin1-deb1 and somme2 <= somme1):
                # print("HELLO")
                sys.stdout.write(" ".join(list(map(str, L[deb1:fin1])))+"\n")
                sys.stdout.write(" ".join(list(map(str, L[deb2:fin2])))+"\n")
            else:
                sys.stdout.write(" ".join(list(map(str, L[deb2:fin2])))+"\n")
                sys.stdout.write(" ".join(list(map(str, L[deb1:fin1])))+"\n")


    def case_product_equals_0():
        # On trouve une séquence dont la somme est nulle
        best_sub_sequence = None # couple (deb, fin)
        for deb in range(sizeL): # indice de début de la liste
            for fin in range(deb+1, sizeL+1): # Fin exclus
                lenKey = fin-deb
                somme = ECC[fin] - ECC[deb] 
                if somme == 0:
                    # print(deb, fin, somme)
                    if (best_sub_sequence is None) or (best_sub_sequence[1]-best_sub_sequence[0] < lenKey):
                        best_sub_sequence = (deb, fin)
        if best_sub_sequence is None:
            sys.stdout.write("IMPOSSIBLE\n")
        else:
            sys.stdout.write(" ".join(list(map(str, L)))+"\n") # On affiche la liste en entier
            sys.stdout.write(" ".join(list(map(str, L[best_sub_sequence[0]:best_sub_sequence[1]])))+"\n") # 
    

    ECC = getECC(L)
    if P!=0:
        case_product_not_equals_0()
    else: # Le produit est nul
        case_product_equals_0()
        
    
if __name__ == "__main__":
    solve()