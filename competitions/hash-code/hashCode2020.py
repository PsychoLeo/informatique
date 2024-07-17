import sys
from math import ceil

def read():
    return sys.stdin.readline().strip()

# def write(txt):
#     sys.stdout.write(txt+'\n')


def main():
    # sys.stdout.write("%d\n" %nbIntersec)
    MULTIPLICATOR = 4.5 # a faire varier

    SCHEDULE = [] # Liste des intersections dont on va donner le schedule + schedule

    for inter in range(nbIntersec): # Pour chaque intersection
        # On calcule la somme 
        sommeFrequenceEntrantes = 0
        frequencesPourChaqueEntree = []
        nbFeuxAGerer = 0

        for street in ruesEntrantes[inter]: # Pour chaque street entrante
            if frequenceUsage.get(street,0) >0:
                nbFeuxAGerer +=1
                sommeFrequenceEntrantes += frequenceUsage[street]
                frequencesPourChaqueEntree.append((street, frequenceUsage[street]))

        
        if sommeFrequenceEntrantes > 0 : # i.e. on a du traffic entrant
            
            sched = [inter, len(frequencesPourChaqueEntree)]

            # sys.stdout.write("%d\n" %nbFeuxAGerer) # On affiche le nombre de feux qu'on va allumer
            streetAndTempsAlloue = []

            for street, freq in frequencesPourChaqueEntree: # Pour chaque rue et son traffic
                ratio = freq/sommeFrequenceEntrantes
                tempsAlloue = min(t-1, ceil(MULTIPLICATOR * ratio))

                # sys.stdout.write(f"{street} {tempsAlloue}\n")
                streetAndTempsAlloue.append((street, tempsAlloue))

            sched.append(streetAndTempsAlloue)
            SCHEDULE.append(sched[:])

    sys.stdout.write("%d\n" %len(SCHEDULE)) # On affiche le nombre de schedule
    for sched in SCHEDULE:
        sys.stdout.write("%d\n" %sched[0]) #on affiche l'intersection
        sys.stdout.write("%d\n" %sched[1]) #on affiche le nombre de feux qu'on gère
        for street, tempsAlloue in sched[2]:
            sys.stdout.write(f"{street} {tempsAlloue}\n")
        

if __name__ == '__main__':

    # t : duree de la simulation
    # nbIntersec : nombre d'intersections
    # nbStreets : Nombre de rues
    # nCars :number of cars
    # bonus : bonus pour chaque voiture qui arrive à sa destination

    t,nbIntersec,nbStreets, nCars,bonus = map(int, read().split())
    
    # graph_out = [[] for _ in range(nbIntersec)] # liste d'adjacence du graphe, tuple neigbor + distance
    # graph_in = [[] for _ in range(nbIntersec)] # liste d'adjacence du graphe, tuple neigbor + distance

    distances = [[0]*nbIntersec for _ in range (nbIntersec)] # matrice d'adjacence
    nomsRues = [[None]*nbIntersec for _ in range (nbIntersec)] # Le nom de la rue, s'il y en a une, reliant les intersections i et j


    ruesEntrantes = [[] for _ in range (nbIntersec)]
    ruesSortantes = [[] for _ in range (nbIntersec)]

    # ! LECTURE DES RUES
    for i in range (nbStreets) : # pour chaque street
        line = read().split() # line d'information

        A,B = map(int, line[:2])
        streetName = str(line[2])
        longueur = int(line[3])
        
        ruesEntrantes[B].append(streetName)
        ruesSortantes[A].append(streetName)
        
        nomsRues[A][B] = streetName
        distances[A][B] = longueur
    
    paths = [[None] for _ in range(nCars)]

    frequenceUsage = dict() # Pour chaque nom de rue, sa fréquentation

    #! LECTURE DES VOITURES
    for i in range (nCars) : # pour chaque voiture
        nbStreetsToMove, *streets = read().split()
        nbStreetsToMove = int(nbStreetsToMove)
        paths[i] = streets
        
        for street in streets:
            # Il faut pour cette rue
            if street not in frequenceUsage :
                frequenceUsage[street] =  1
            else :
                frequenceUsage[street] += 1

    main()
