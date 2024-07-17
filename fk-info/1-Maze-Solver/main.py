import queue
import time
from enum import Enum

class Directions(Enum):
    UP = "U"
    RIGHT = "R"
    DOWN = "D"
    LEFT = "L"


class Maze :
    """
    Maze class
    """

    def __init__ (self, maze):
        self.maze = self.loadFromTextFile(maze)
        self.width = len(self.maze[0])
        self.height = len(self.maze)
        self.start = (self.findStart()[0], self.findStart()[1])
        self.exit = self.findExitCoordonates()

    def tryFindSolution(self):
        solutionPath = self.solve()
        self.coloriseSolution(solutionPath)
        print(self)
        

    def loadFromTextFile(self, maze):
        """
        Read a text file to load a maze
        """
        with open (maze, 'r') as f:
            lignes = f.readlines()
            maze = [list(ligne.replace("\n", "")) for ligne in lignes]
        return maze

    def __str__ (self):
        """
        Fonction affichant le maze
        """
        aff = ""
        for line in self.maze :
            aff +="".join(line) + "\n"
        return aff

    def findStart (self) :
        """
        Find the starting point
        """
        try  :
            return ((self.maze)[0].index('O'), 0)
        except :
            return 'Starting point not in maze'
    
    def findExitCoordonates (self) :
        """
        Find the starting point
        """
        try  :
            return ((self.maze)[self.height-1].index('O'), self.height-1)
        except :
            return 'Exit point not in maze'

    def coloriseSolution(self, solutionPath):
        position = list(self.start)
        for d in solutionPath:
            if d == Directions.UP.value:
                position[1]-=1 # On diminue selon l'axe y
            elif d == Directions.DOWN.value:
                position[1]+=1 # On augmente selon l'axe y
            elif d == Directions.RIGHT.value:
                position[0]+=1 # On augmente selon l'axe x
            elif d == Directions.LEFT.value:
                position[0]-=1 # On diminue selon l'axe x
            self.maze[position[1]][position[0]] = "o"


    def solve(self):
        """
        Résous le labyrinthe grâce à une FIFO
        U ==> UP
        D ==> DOWN
        R ==> RIGHT
        L ==> LEFT
        """
        pathes = queue.Queue()
        pathes.put("D")
        solutionPath = ""
        position = self.start[:]
        solutionTrouvee = False
        longueur = 0
        startTime = time.time()
        listeDesPositionsAtteignables = set()
        while not solutionTrouvee:
            path = pathes.get() # On récupère un chemin
            #* Affichage pour les cas long
            # if len(path)!=longueur:
            #     longueur = len(path)
                # print(longueur)
            # print(path)
            position = self.findLastPointOfPath(path) # On récupère le dernier point de ce chemin
            if not position in listeDesPositionsAtteignables:
                if position == self.exit: # Si ce point et l'arrivée, on a fini !
                    solutionPath = path
                    solutionTrouvee = True # On a trouvé la solution
                    break # On sort de la boucle
                if len(path) >= 1000: # On se casse parce qu'on ne trouve pas la solution
                    break
                for d in self.findWays(position, path[-1]):
                    pathes.put(path+d) # On ajoute les positions possibles
                listeDesPositionsAtteignables.add(position)
        print(f"Path solution in {len(solutionPath)} moves : {solutionPath}".format(solutionPath))
        print(f"Solution found in {time.time()-startTime}s")
        return solutionPath
    


    def findLastPointOfPath(self, path):
        x, y = self.start
        xFinal = x + path.count(Directions.RIGHT.value)-path.count(Directions.LEFT.value)
        yFinal = y + path.count(Directions.DOWN.value)-path.count(Directions.UP.value)
        return (xFinal, yFinal) # Tuple des coordonnées de la position en fin de chemin
            
    def findWays (self, point, lastMove):
        """
        With two point coordinates, returns the possible direction to go (tuple)
        U ==> UP
        D ==> DOWN
        R ==> RIGHT
        L ==> LEFT
        Last move is the last move taken by the path
        """
        x, y = point # coordonnées du point
        Up, Dp, Lp, Rp = (y>0), (y<self.height-1), (x>0), (x<self.width-1) # Up possible, DownPossible,...
        result = [] # possibilités de mouvement à partir du point (liste pour y rajouter des éléments)
        
        if self.maze[y+1][x] in (' ', 'O') and lastMove != Directions.UP.value and Dp: # case du bas libre et dernier mouvement != haut
            result.append (Directions.DOWN.value)
        if self.maze[y-1][x] in (' ', 'O') and lastMove != Directions.DOWN.value and Up: # case du haut libre et dernier mouvement != bas
            result.append (Directions.UP.value)
        if self.maze[y][x+1] in (' ', 'O') and lastMove != Directions.LEFT.value and Rp: # case de droite libre et dernier mouvement != gauche
            result.append (Directions.RIGHT.value)
        if self.maze[y][x-1] in (' ', 'O') and lastMove != Directions.RIGHT.value and Lp: # case de gauche libre et dernier mouvement != droite
            result.append (Directions.LEFT.value)
        return tuple(result) # Retourne les directions possibles depuis ce point
            

MazeA = Maze('mazeCollection/maze3.txt')
MazeA.tryFindSolution()