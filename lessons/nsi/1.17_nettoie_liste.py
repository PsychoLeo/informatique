def nettoie (liste, i=0) :
    if i == len(liste)-1 :
        return liste
    else :
        if liste[i] == liste[i+1] :
            del liste[i+1]
            return nettoie(liste, i)
        else :
            return nettoie(liste, i+1)