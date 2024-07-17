import pprint
import copy
import numpy as np

class Arete:
    """
    Deux extremités (x, y)
    weight
    """
    
    def __init__(self, x, y, weight):
        self.x = x
        self.y = y
        self.weight = weight

    def __str__(self):
        return f"({self.x}, {self.y}, {self.weight})"

    @property # pour faire self.tuple_xy au lieu de self.tuple_xy()
    def tuple_xy(self) :
        return (self.x, self.y)

class Graph:
    """
    Intialisation: 
        n: le nombre de sommets
        m: le nombre d'arêtes
        arrayOfAretes: liste des arêtes
        Table d'adjacence

    Méthode 1:
        Renvoyer un graphe avec un point en moins sur le graphe d'origine

    Méthode 2:
        Compter le nombre d'éléments connexes
        Renvoie un int
    """

    def __init__ (self, n, m, listeAretes=None, matriceAdjacence=None) :
        self.listeAretes = listeAretes # changer après
        # if matriceAdjacence == None :
        #     self.listeAretes = None # change here
        # else :
        self.n = n # nombre de sommets
        self.m = m # nombre d'arêtes
        if listeAretes and not matriceAdjacence:
            self.adjMatrix = self.adjacencyMatrix()


    def __copy__(self):
        # return Graph(self.n, self.m, None, copy.deepcopy(self.adjMatrix))
        return self

    def __repr__(self):
        """
        Représentation de la matrice
        """
        # print (f"""Graph({self.n}, {self.m}, {self.listeAretes}, \nmatriceAdjacence=\n{pprint.pprint(self.adjMatrix)})""") #Pour réinstancier
        print (f"""Graph({self.n}, {self.m}, {[str(arete) for arete in self.listeAretes]}, \nmatriceAdjacence=\n{np.matrix(self.adjMatrix)})""") # Pour lire
        return None
    def __str__(self):
        """
        Représentation de la matrice
        """
        # print (f"""Graph({self.n}, {self.m}, {self.listeAretes}, \nmatriceAdjacence=\n{pprint.pprint(self.adjMatrix)})""") #Pour réinstancier
        return (f"""Graph({self.n}, {self.m}, {[str(arete) for arete in self.listeAretes]}, \nmatriceAdjacence=\n{np.matrix(self.adjMatrix)})""") # Pour lire

    def countMaxDegree(self):
        """
        Renvoie le sommet qui a le plus de connections et le nombre de ses connections
        """
        max_degree = [0, 0] # le sommet, son nombre de connection 
        for i_node, node_connections in enumerate(self.adjMatrix):
            connection = self.n - node_connections.count(0) # on compte le nombre de connections du sommet
            if connection > max_degree[1]:
                max_degree = max_degree[i_node, node_connections]
        return max_degree[0], max_degree[1] # C un tuple ! 
        

    def adjacencyMatrix (self) :
        '''
        Returns the adjacency matrix of a graph, for example :
        [[0, 1, 0], 
         [1, 0, 0],
         [0, 0, 0]] => mon dessin est nul
        '''
        matrix = [[0]*self.n for _ in range (self.n)] # initialiser matrice 2D avec seulement des 0
        for arete in self.listeAretes :
            A, B = arete.y, arete.x
            matrix[A][B] = arete.weight # completing adjacency matrix
            matrix[B][A] = arete.weight # comme c'est un graphe non directionnel : A=>B et B=>A
        # pprint.pprint (matrix) # joli output
        return matrix

        
    def retireSommet(self, sommet):
        """
        Retourne un graphe sans le sommet
        nouveau graphe
            n'=n-1
            nouvelle table d'adjacence    
        """
        nouveauGraphe = copy.deepcopy(self) # on effectue une copie du graphe
        nouveauGraphe.n = self.n-1 # On a n-1 points
        # NB: il faut aussi changer m et listeArretes mais on va pas le faire tout de suite car pas urgent
        # 1. On suprrime la ligne d'indice sommet
        #* AUTRE MÉTHODE del nouveauGraphe.adjMatrix[sommet]
        # print(nouveauGraphe.adjMatrix)
        nouveauGraphe.adjMatrix.pop(sommet)
        # print(nouveauGraphe.adjMatrix)
        #2. On supprime la colonne d'indice sommet = on supprime l'index sommet de chaque sous liste
        # la liste comprehension ne marche pas bien :(
        for line in nouveauGraphe.adjMatrix:
            line.pop(sommet)
        # print(nouveauGraphe.adjMatrix)
        # nouveauGraphe.m = 0
        # 2ème méthode:
        # for ligne in nouveauGraphe.adjMatrix:
        #     ligne.pop(sommet)
        return nouveauGraphe

    
    def findSommetsConnexeTo(self, origine, notVisited):
        """
        Renvoie tous les sommets d'un groupe connexe
        """
        notVisited.remove(origine) # on retire le sommet des non visités
        # print(self.adjMatrix)
        for voisin, weight in enumerate(self.adjMatrix[origine]): # Pour chaque voisin de ce point
            if weight !=0 and voisin in notVisited: # On y est connecté et on ne l'a pas encore vu
                self.findSommetsConnexeTo(voisin, notVisited) # On répète le processus pour ce point
    
    def countConnexe(self):
        """
        Compte le nombre d'éléments connexe dans le groupe
        => éléments connexes : 
        """
        notVisited = list(range(0,self.n)) # Liste des éléments qui n'ont pas encore été visité
        numberOfConnexElements = 0
        while notVisited:
            numberOfConnexElements+=1 # On ajoute un nouveau groupe connexe
            origine = notVisited[0] # On prend un point origine
            self.findSommetsConnexeTo(origine, notVisited) # On enlève de la liste des non visités tous les éléments
        return numberOfConnexElements # On retourne le nombre d'éléments connexes

    def findWeakNode(self):
        """
        Trouve le point le plus faible
        """
        weak = [0, 1] #LIste point le plus faible et nombre éléments connexes si l'on retire ce point
        for sommet in range(self.n):
            print(f"Try NODE={sommet}")
            newGraph = self.retireSommet(sommet)
            nGpesConnexes = newGraph.countConnexe()
            if weak[1] < nGpesConnexes:
                weak = [sommet, nGpesConnexes]
        return weak[0], weak[1]

    def arbreCouvrantCoutMinimalPrim(self):
        """
        Trouve l'arbre couvrant de coût minimal
        Pour cela, on s'inspire de l'algorithme de Prim
        """
        # Soit on crée un graphe qui va être notre arbre couvrant
        # A = Graph(1,0) # Il possède un seul point et aucune arrête
        # Soit on instancie l'arbre à la fin, une fois qu'on connaît toutes ses arrêtes
        #* aretes : listes de tuples (x,y) => lien entre le node x et le node y
        #* nodes / points : liste de points (avec leur numéro)
        
        if self.countConnexe()!=1: # Le graphe n'est pas connexe
            # return "ATTENTION LE GRAPHE N'EST PAS CONNEXE"
            return float("+inf")
        if self.n == 0:
            return "ATTENTION LE GRAPHE N'A PAS DE SOMMETS"
        pointsArbre = [0] # On part avec le point 0
        aretesArbre = [] #Arrêtes de l'arbre final
        while len(pointsArbre) < self.n: # Tant que l'arbre ne recouvre pas le graphe
            # Algo Hubert
            # aretesPotentielles= []
            bestWeight = 10000000000000 # Le mieux serait de prendre l'arrête de coût max
            bestX = 0 # On initialise X
            bestY = 0 # Y
            for x, line in enumerate(self.adjMatrix): # Pour chaque point de départ possible
                if x in pointsArbre: # On part d'un point dans notre arbre
                    for y, weight in enumerate(line): # Pour chaque connection de ce point
                        if 0 < weight  and weight < bestWeight  and y not in pointsArbre: # S'il y a une connection entre notre arbre et le reste du graphe
                            bestWeight = weight
                            bestX = x
                            bestY = y
            #il faut ajouter l'arête de poid minimum
            pointsArbre.append(bestY) # on ajoute le point le plus accessible
            aretesArbre.append(Arete(bestX, bestY, bestWeight)) # on ajoute la connection

        return Graph(len(pointsArbre), len(aretesArbre), aretesArbre)


    
    def arbreCouvrantCoutMinimalPrimBis(self):
        """
        Trouve l'arbre couvrant de coût minimal
        Pour cela, on s'inspire de l'algorithme de Prim
        """
        if self.countConnexe()!=1: # Le graphe n'est pas connexe
            # return "ATTENTION LE GRAPHE N'EST PAS CONNEXE"
            return float("+inf")
        if self.n == 0:
            return "ATTENTION LE GRAPHE N'A PAS DE SOMMETS"
        pointsArbre = [0] # On part du point 0
        aretesArbre = [] # Arêtes de l'arbre final
        while len(pointsArbre) < self.n : # Tant que l'arbre ne recouvre pas le graphe
            mini, best, best_node = float("+inf"), None, (None, None)
            for i in pointsArbre : # Pour chaque point de notre arbre
                for j in range (self.m) :
                    # j ne fait pas parti de l'arbre, il existe une connection et elle a un poids plus faible qu'auparavant
                    if j not in pointsArbre and self.adjMatrix[i][j] > 0 and self.adjMatrix[i][j] < mini : 
                        mini = self.adjMatrix[i][j]
                        best, best_node = j, (i, j)
            pointsArbre.append(best) # liste des meilleurs voisins
            aretesArbre.append(best_node) # liste des meilleurs nodes
        return pointsArbre, aretesArbre