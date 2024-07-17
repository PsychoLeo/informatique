f = int(input())
membres = int(input())
familles = []
for i in range (f) :
    familles.append(input())
c = int(input())
cartes = list(input())

manquants = []
for famille in familles :
    commun = 0
    for member in famille :
        if member in cartes :
            commun += 1
    manquants.append(commun)

print (membres-max(manquants))