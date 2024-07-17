nbCours, nbPrendre = map(int, input().split())

def choixCours(n=0, last=1, cours = []) :
    # revient à prendre k éléments d'un ensemble de n éléments (k parmi n possibilités)
    if n == nbPrendre :
        print (' '.join(cours))
    else :
        for i in range (last, n+nbCours+2-nbPrendre) :
            choixCours(n+1, i+1, cours+[str(i)])

if nbPrendre == nbCours :
    print (' '.join(map(str, list(range(1, nbCours+1)))))
elif nbPrendre < nbCours :
    choixCours()