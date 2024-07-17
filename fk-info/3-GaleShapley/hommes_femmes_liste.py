"""
==> Remplir ces dictionnaires avec des préférences
"""
import random

# Il y a AUTANT d'hommes que de femmes
#* Gens qui proposent = hommes

# Liste de longueur nombre d'hommes et comportant n sous listes de longueur nombre de femmes, les classant

# hommes = [] 
# *Ceux qui acceptent ou déclinent = femmes
# Liste de longueur nombre de femmes et pour chaque femme, il y a une liste de ses préférences
# femmes = [] 
# Nous utiliserons des dictionnaires pour associer à chaque homme sa liste de préférence de femmes et vice-versa

def generator(n):
    """
    Génère les liste 2D hommes/ femmes:
    hommes: classement des femmes pour chaque hommes
    femmes : notation des hommes
    """
    l = list(range(n))
    hommes = []
    femmes = []
    
    for i in range(n):
        random.shuffle(l)
        hommes.append(l[:])
        random.shuffle(l)
        femmes.append(l[:])
    return hommes, femmes