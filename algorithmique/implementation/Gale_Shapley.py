import sys
from collections import deque
import random

# Il y a AUTANT d'hommes que de femmes
# Nous utiliserons des dictionnaires pour associer à chaque homme sa liste de préférence de femmes et vice-versa

def read() :
    """
    Lis plus rapidement l'input
    """
    return sys.stdin.readline().strip()


def genHF (hommes, femmes) :
    """
    input : listes d'hommes et de femmes
    output : dictionnaires d'hommes, dictionnaire de femmes
    """
    hommesChoix = {homme:random.sample(femmes, len(femmes)) for homme in hommes}
    femmesChoix = {femme:random.sample(hommes, len(hommes)) for femme in femmes}
    for i in femmesChoix :
        print(f"{i} : {femmesChoix[i]}")
    for i in hommesChoix :
        print (f"{i} : {hommesChoix[i]}")
    print()
    return (hommesChoix, femmesChoix)


def mariagesStables (hommes, femmes) :
    '''
    :param: n est le nombre de femmes / hommes
    :param: hommes est une liste deux dés avec le classement par préférences des femmes pour chaque homme
    :param: femmes idem mais pour les femmes
    :return: listes couples hommes/ gemmes stables
    => Algorithme de Gale-Shapley : O(n^2)
    1. On associe tous les célibataires (provisoirement) à leur femme préférée
    2. On regarde dans les femmes (si une femme a plusieurs hommes associés à elle, alors on prend celui qu'elle pref.)
    3. On continue jusqu'à ce que tous les hommes soient mariés
    '''
    # Dès qu'un homme demande à une femme, on l'enlève de ses préférences
    celibs = deque(hommes.keys()) # célibataires hommes
    couples = {femme:None for femme in femmes} # couples formés
    while celibs : # Tant qu'il y a des célibataires
        celib = celibs.popleft() # on prend un homme au hasard
        pref = hommes[celib][0] # femme préférée de cet homme 
        del hommes[celib][0]
        if couples[pref] == None : # si la femme choisie n'est fiancée avec personne
            couples[pref] = celib # on la fiance avec l'homme actuel
        else : # faire choisir l'homme des 2 (fiancé + nouveau) qu'elle préfère
            if femmes[pref].index(couples[pref]) > femmes[pref].index(celib) : # si elle préfère le célibataire que son fiancé
                celibs.append(couples[pref])
                couples[pref] = celib
            else : # si elle préfère rester avec son fiancé
                celibs.append(celib) # il reste célibataire
    for couple in couples :
        print (couple, couples[couple])
    return None


def gale_shapley(men, women):
    '''Algorithme du livre'''
    n = len(men)
    assert n == len(women)
    suiv = [0]*n
    mari = [None]*n
    rang = [[0]*n for j in range (n)]
    for j in range (n):
        for r in range (n):
            rang[j][women[j][r]] = r
    celib = deque(range(n))
    while celib :
        i = celib.popleft()
        j = men[i][suiv[i]]
        suiv[i] += 1
        if mari[j] is None :
            mari[j] = i
        elif rang[j][mari[j]] < rang[j][i] :
            celib.append(i)
        else :
            celib.append(mari[j])
            mari[j] = i
    print(mari); return None


if __name__ == '__main__' :
    genRandom = True
    if genRandom :
        # possiblesH = ["Hubert", "Kib", "Leo"]
        # possiblesF = ["Jeanne", "Marie", "Pauline"]
        possiblesH, possiblesF = range(4), range(4)
        hommes, femmes = genHF(possiblesH, possiblesF)
        hommesList, femmesList = list(hommes.values()), list(femmes.values())
    else :
        hommes = {
            "Jon":["Dae", "Cer", "Bri"], 
            "Jai":["Dae", "Cer", "Bri"], 
            "Dro":["Cer", "Dae", "Bri"]
        }
        femmes = {
            "Dae":["Dro", "Jon", "Jai"],
            "Cer":["Jon", "Jai", "Dro"],
            "Bri":["Dro", "Jai", "Jon"]
        }
    print("Couples organisés : "); mariagesStables(hommes, femmes)
    print("Couples organisés (livre) : "); gale_shapley(hommesList, femmesList)


##########################
##### Test refaire #######
##########################

def main():
    nh, nf = map(int, read().split()) # nb hommes et femmes
    hommes = {}
    femmes = {}
    for i in range (nh) :
        pref = read().split()
        currentH, *choixFemmes = pref
        hommes[currentH] = choixFemmes
    for i in range (nf) :
        pref = read().split()
        currentF, *choixHommes = pref
        femmes[currentF] = choixHommes
    gale_shapley(hommes, femmes)


def gale_shapley (hommes, femmes) :
    # Si les hommes choisissent en premier
    celib = deque(hommes.keys())
    couples = {femme:0 for femme in femmes}
    while celib :
        current = celib.popleft()
        pref = hommes[current][0] # femme préférée de cet homme
        del hommes[current][0] # enlever la femme préférée de cet homme pour ne pas qu'il redemande
        if couples[pref] == 0 :
            couples[pref] = current
        else : # si la femme est deja couplée
            hommeActuel = couples[pref]
            if femmes[pref].index(hommeActuel) < femmes[pref].index(current) : # si elle pref l'ancien
                celib.append(current)
            else :
                celib.append(hommeActuel)
                couples[pref] = current
    for f in couples : # pour chaque couple femme / homme
        print (f, couples[f]) 

main()

"""
3 3
A E L S
B L E S
C L E S
L A C B
E B A C
S C A B
"""