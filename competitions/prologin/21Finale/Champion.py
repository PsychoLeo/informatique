from api import *
from math import sqrt

mesBebes = []
largeur, hauteur = 0, 0
me, adv = None, None

def partie_init(): # Fonction appelée au début de la partie.
    # moi -> numéro de notre joueur
    # adversaire -> numéro de l'adversaire
    # liste_bebes -> tous les objets de bebes pandas
    me, adv = moi(), adversaire()
    mesBebes = [bebe for bebe in liste_bebes() if bebe.id_bebe_joueur == me] # -> liste avec les bebes à aller chercher
    largeur, hauteur = carte_info.taille_x, carte_info.taille_y

    # Trouver min(mesBebes, key=dist) et se diriger vers là (gagner le plus de points possibles)

def findNearestBebe(currPos) :
    # sqrt((x1-x2)^2+(y1-y2)^2)) -> renvoie le minimum de cette fonction
    x, y = currPos.x, currPos.y
    minDist, bebeProche = float("+inf"), None
    for bebe in mesBebes :
        xBebe, yBebe = bebe.bebe_pos.x, bebe.bebe_pos.y
        if sqrt((x-xBebe)**2+(y-yBebe)**2) < minDist: 
            minDist = sqrt((x-xBebe)**2+(y-yBebe)**2) 
            bebeProche = bebe
    return bebeProche


def optiFindNearestBebe() :
    # Implémenter Dijkstra pour trouver un plus court chemin entre moi et bebe Panda
    # version opti de la fonction précédente
    pass

def jouer_tour(): # Fonction appelée à chaque tour.
    currPanda = info_tour().id_panda_joue
    currPos = position_panda(me, currPanda)
    nearestOwnBebe = findNearestBebe(currPos)



def partie_fin(): # Fonction appelée à la fin de la partie.
    # TODO
    pass
