import sys
# from hommes_femmes import hommes, femmes
from hommes_femmes_liste import generator

def read() :
    """
    Lis plus rapidement l'input
    """
    return sys.stdin.readline().strip()

def write (txt) :
    """
    Écris plus rapidement en sortie
    """
    sys.stdout.write(str(txt)+"\n")

def galeShapeley (n, hommes, femmes) :
    '''
    :param: n est le nombre de femmes / hommes
    :param: hommes est une liste deux dés avec le classement par préférences des femmes pour chaque homme
    :param: liste 2D avec la note de chaque homme pour la femme f
    :return: listes couples hommes/ gemmes stables
    => Algorithme de Gale-Shapley : O(n^2)
    0. On associe tous les célibataires (provisoirement) à leur femme préférée
    1. On regarde dans les femmes (si une femme a plusieurs hommes associés à elle, alors on prend celui qu'elle pref. et elles envoie chier les autres)
    2. On continue jusqu'à ce que tous les hommes soient casés

    '''
    affectationProvisoires = [None]*n # Repère l'homme avec qui chaque femme est actuellement fiancé
    celib = list(range(n)) # Il y a n célibataires hommes indexés 0 à n
           
    
    
    while celib: # Tant qu'il reste des hommes célibataires
        h = celib[0] # On prend le premier célibataire
        # write(" ")
        # write(celib)
        # write(affectationProvisoires)
        for line in hommes:
            write(line)
        femme_desire = hommes[h][0]
        if affectationProvisoires[femme_desire]==None: # Si elle est libre 
            affectationProvisoires[femme_desire] = h # Elle prend cet homme
            celib.pop(0) # L'autre n'est plus célibataire
        elif femmes[femme_desire][affectationProvisoires[femme_desire]]>femmes[femme_desire][h]: # La note du gars actuel est moins bonne que le gars qui se présente
            le_cocu = affectationProvisoires[femme_desire] # On récupère l'homme qui se prend un rateau
            celib.append(le_cocu) # il devient célibataire
            affectationProvisoires[femme_desire] = h # Elle prend cet homme
            celib.pop(0) # L'autre n'est plus célibataire
        hommes[h].pop(0) # On perd le souhait
    return [(affectationProvisoires[f],f) for f in range(n)] #on retourne la situation stable

def consoleInput():
    """
    Lance l'algo GaleShapeley avec input
    """
    n = int(read())
    hommes = []
    femmes = []
    for i in range(n):
        hommes.append(list(map(int, read().split()))) # Femmes par ordre de préférence le l'homme i
    for i in range(n):
        femmes.append(list(map(int, read().split()))) # Note de chaque homme pour la femme i
    write(hommes)
    write(femmes)
    
    write(galeShapeley(n, hommes, femmes))

def automatic(n):
    hommes, femmes = generator(n)
    write("Hommes")
    for line in hommes:
        write(line)
    write("Femmes")
    for line in femmes:
        write(line)
    write(galeShapeley(n, hommes, femmes))



automatic(10)

# if __name__ == "__main__":
#     n = int(read())
    