l = [0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0]
n = len(l)
i = 0
state = "LIBRE" # ou "OCCUPE"

def nbSacs() :
    return n//2

def sacDansCase() :
    return l[i] == 1

def avance(d) :
    i = (i+d) % n

def recule(d) :
    i = (i-d) % n

def ramasse() :
    if l[i] == 1 and state == "LIBRE" :
        state = "OCCUPE"
        l[i] = 0
    elif l[i] == 0 :
        print("Essaye de ramasser alors qu'il n'y a rien")
    elif l[i] == 1 and state == "OCCUPE" :
        print("Essaye de ramasser alors que déjà occupé")

def pose() :
    if l[i] == 0 and state == "OCCUPE" :
        state = "LIBRE"
        l[i] = 1
    elif l[i] == 1 :
        print("Essaye de poser alors qu'il y a quelque chose")
    elif l[i] == 0 and state == "LIBRE" :
        print("Essaye de poser alors que ne porte rien")

        