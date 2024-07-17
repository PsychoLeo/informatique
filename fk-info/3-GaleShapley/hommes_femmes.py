import random
# from collections import deque 

# Il y a AUTANT d'hommes que de femmes
# Nous utiliserons des dictionnaires pour associer à chaque homme sa liste de préférence de femmes et vice-versa

def genHF (hommes, femmes) :
    """
    input : listes d'hommes et de femmes
    output : dictionnaires d'hommes, dictionnaire de femmes
    """
    hommesChoix = {homme:random.shuffle(femmes) for homme in hommes}
    femmesChoix = {femme:random.shuffle(hommes) for femme in femmes}
    return (hommesChoix, femmesChoix)

possiblesH = ["Kib", "Leo", "Hubert{|z|=1}", "Mario", "Sebastien", "Gabriel"]
possiblesF = ["Jeanne", "Marie", "Pauline", "LaTragne", "LeTec", "Nordin"]

hommes, femmes = genHF(possiblesH, possiblesF)