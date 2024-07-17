
def genealogie_divine(f, m, familles, c, cartes):
    """
    :param f: Le nombre de familles
    :type f: int
    :param m: Le nombre de membres par famille
    :type m: int
    :param familles: Les différentes familles possibles dans le jeu
    :type familles: list[list[str]]
    :param c: Le nombre de cartes dans la main de Joseph
    :type c: int
    :param cartes: Les cartes dans la main de Joseph
    :type cartes: list[str]
    """
    # TODO Afficher le nombre minimal de cartes nécessaires à Joseph pour
    # compléter une famille. *0* si une famille est déjà complétée.
    return min([compare(famille, cartes) for famille in familles]) # Rtourne le minimum du nombre de cartes qu'il faut pour former chaque famille

def compare(famille, main):
    """
    cette fonction compare une famille et les cartes dans la main de Joseph
    Elle renvoie le nombre de cartes qui lui manque
    """
    nbre_maquante = 0
    for dieu in famille: # Pour chaque dieu de la famille
        if dieu not in main: # Si ce dieu n'est pas dans la main
            nbre_maquante+=1 # Alors il manque une carte
    return nbre_maquante #à la fin, on renvoie le nombre de cartes manquantes pour cette famille


if __name__ == '__main__':
    f = int(input())
    m = int(input())
    familles = [list(input()) for _ in range(f)]
    c = int(input())
    cartes = list(input())
    print(genealogie_divine(f, m, familles, c, cartes))
