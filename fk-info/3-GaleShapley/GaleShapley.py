import sys
from hommes_femmes import hommes, femmes
from collections import deque

def read() :
    """
    Lis plus rapidement l'input
    """
    return sys.stdin.readline().strip()

def write (txt) :
    """
    Écris plus rapidement en sortie
    """
    sys.stdout.write(txt)

def mariagesStables (hommes, femmes) :
    '''
    :param: n est le nombre de femmes / hommes
    :param: hommes est une liste deux dés avec le classement par préférences des femmes pour chaque homme
    :param: femmes idem mais pour les femmes
    :return: listes couples hommes/ gemmes stables
    => Algorithme de Gale-Shapley : O(n^2)
    1. On associe tous les célibataires (provisoirement) à leur femme préférée
    2. On regarde dans les femmes (si une femme a plusieurs hommes associés à elle, alors on prend celui qu'elle pref.)
    3. On continue jusqu'à ce que tous les hommes soient casés
    '''
    # Dès qu'un homme demande à une femme, on l'enlève de ses préférences
    celibs = deque(hommes.values()) # célibataires hommes
    couples = {femme:None for femme in femmes} # couples formés
    while celibs : # Tant qu'il y a des célibataires
        celib = celibs.popleft() # on prend un homme au hasard
        pref = hommes[celib][0] # femme préférée de cet homme 
        del hommes[celib][0]
        if couples[pref] == None : # si la femme choisie n'est fiancée avec personne
            couples[pref] = celib # on la fiance avec l'homme actuel
        else : # faire choisir l'homme des 2 (fiancé + nouveau) qu'elle préfère
            if femmes[pref].index(couples[pref]) < femmes[pref].index(celib) : # si elle préfère le célibataire que son fiancé
                celibs.append(couples[pref])
                couples[pref] = celib
            else : # si elle préfère rester avec son fiancé
                celibs.append(celib) # il reste célibataire
    for couple in couples :
        print (couple, couples[couple])


if __name__ == '__main__' :
    mariagesStables(hommes, femmes)