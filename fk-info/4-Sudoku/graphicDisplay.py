import pygame as pg 
import enum

import random
import numpy as np
import pprint
from collections import Counter

from sudokuBibli import list_sudokus


class Sudoku:
    """
    class pour le sudoku
    """

    def __init__ (self):
        self.SOLUTIONS = []
        self.grille_initiale = random.choice(list_sudokus) # Pour avoir la grille initiale avec les nombres que l'on ne peut pas changer
        # self.grille_initiale = list_sudokus[2] # Pour avoir la grille initiale avec les nombres que l'on ne peut pas changer
        self.grille = [row[:] for row in self.grille_initiale] # Avoir la grille que l'on va changer au fur et à mesure
        
        # Dimensions
        self.number_of_rows = len(self.grille)
        self.number_of_columns = len(self.grille[0])
        if self.number_of_columns != self.number_of_rows: raise Exception("The sudoku given is not a square !")
        self.size = (self.number_of_rows, self.number_of_columns)
        
        self.number_of_carres = None

    def addNumber(self, position, number):
        """
        Input : a tuple of coordinates (x, y) and a number
        Add a number to the grid
        """
        x, y = position
        #! Exceptions
        if not 1<=number<=self.number_of_rows: raise Exception("Number incorrect !") # Le nombre n'est pas compris ente 1 et 9
        if not 0<=x<self.number_of_rows: raise Exception("X coordinate isn't is the sudoku") #  La coordonnée X est trop grande ou trop petite
        if not 0<=y<self.number_of_columns: raise Exception("Y coordinate isn't is the sudoku") #  La coordonnée Y est trop grande ou trop petite
        if self.grille_initiale[x][y] != 0: raise Exception("This number cannot be modified !") # Ce nombre ne peut pas être modifié !
        if self.possible(position, number) :
            self.grille[x][y] = number
        else :
            raise Exception("It is not possible !")

    def rowCorrect(self, row):
        """
        Input : the index of a row
        Output : if this row is correct
        """
        row = [i for i in self.grille[row] if i!=0] # ligne sans les zéros
        return len(set(row)) == len(row) # vérifie si la liste n'a pas de doublons (autres que 0) --> correcte
    
    def columnCorrect(self, columnID):
        """
        Input : the index of a column
        Output : if this column is correct 
        """
        column = [self.grille[i][columnID] for i in range(len(self.grille)) if self.grille[i][columnID]!=0]
        return len(set(column)) == len(column) # Vérifie si la liste sans doublons a la même longueur que la liste normale = pas de doublons

    def giveCarre(self, carreId):
        """
        Input : a tuple of positions for a square
        Output : a one-dimensional list of all values inside the square
        """
        x, y = carreId
        return [self.grille[i][j] for i in range (x*3, x*3+3) for j in range (x*3, x*3+3)]
    
    def carreCorrect(self, carreID):
        """
        https://www.guru99.com/python-counter-collections-example.html --> idée
        """
        carre = [i for i in self.giveCarre(carreID) if i!=0]
        return len(set(carre)) == len(carre)

    def isCorrect(self):
        """
        Output : None
        Output : if the grid is correct
        """
        if all ([self.rowCorrect(i) for i in range (len(self.grille[0]))]) :
            if all ([self.columnCorrect(i) for i in range (len(self.grille))]) :
                if all ([self.carreCorrect((x, y)) for x in range (len(self.grille)//3) for y in range (len(self.grille)//3)]) :
                    return True
        return False

    def possible(self, coordinates, number):
        """
        return if the choice is possible
        """
        y,x = coordinates
        # Verify row
        for i in range(self.number_of_columns):
            if self.grille[y][i] == number:
                return False
        # Verify column
        for i in range(self.number_of_rows):
            if self.grille[i][x] == number:
                return False
        # Verify square
        x0 = (x//3)*3
        y0 = (y//3)*3
        for i in range(3):
            for j in range(3):
                if self.grille[y0+i][x0+j] ==number:
                    return False
        return True

    def solve(self):
        """
        Solve the sudoku
        """
        for y in range(9):
            for x in range(9):
                if self.grille[y][x] == 0:
                    for n in range(1,10):
                        if self.possible((y,x), n):
                            # print(self)
                            self.grille[y][x] = n
                            draw_sudoku(self)
                            self.solve()
                            self.grille[y][x] = 0 # ON retourne au point de départ
                    return
        print(self)
        input("More")

    def create(self):
        """
        Creates a 9x9 sudoku
        """
        pass

    def __repr__(self):
        """
        Affiche 
        """
        return str(np.matrix(self.grille))
        # return str(pprint.pprint(self.grille))

# if __name__ == "__main__":
#     sudoku = Sudoku()
#     while True:
#         x = eval(input("Give the x"))
#         y = eval(input("Give the y"))
#         number = eval(input("New Number"))


pg.font.init()

#* ================== COLORS =====================
class Color(enum.Enum):
    WHITE = (255,255,255)
    BLACK = (0,0,0)
    GRAY = (200,200,200)
    RED = (255,0,0)
    BLUE = (0,0,255)
#* ================== Window =====================
WIDTH, HEIGHT = 750, 750 # Largeur et hauteur de la fenêtre
WIN = pg.display.set_mode((WIDTH, HEIGHT)) # Définir la fenêtre
pg.display.set_caption("Sudoku") # Titre de la fenêtre

#* ========= FONTS ============
NUMBER_FONT = pg.font.SysFont("comicsans", 40)

def draw_sudoku(sudoku):
    """
    Draw a sudoku on the window
    """
    x, y = 70,70 # Starting point
    ROWS = sudoku.number_of_rows
    gap = WIDTH // (ROWS+2)

    WIN.fill(Color.WHITE.value) # Fond d'écran blanc
    #Affichage de la grille
    for i in range(ROWS+1):
        if i % 3 == 0:
            col = Color.BLACK.value
        else:
            col = Color.GRAY.value
        pg.draw.line(WIN, col, (x,int(y+i*gap)),(WIDTH-x, y+i*gap), 3) # Horizontal
        pg.draw.line(WIN, col, (x+i*gap,y),(x+i*gap,HEIGHT-y), 3) # Vertical

    #  Affichage des numéros
    for index_row, row in enumerate(sudoku.grille):
        for index_column, number in enumerate(row):
            if number != 0:
                if sudoku.grille_initiale[index_row][index_column]!=0:
                    text = NUMBER_FONT.render(str(number), 1, Color.RED.value)
                else:
                    text = NUMBER_FONT.render(str(number), 1, Color.BLACK.value)
                WIN.blit(text, (x+index_column*gap+int(gap*0.4),y+index_row*gap+int(gap*0.4)))
    pg.display.update()


def main():
    sudoku = Sudoku()
    draw_sudoku(sudoku)
    input("Start ?")
    sudoku.solve()
    input("fin")

main()














# def placeNumbers(sudoku_array):
#     font = pg.font.Font(None, 36)
#     for row in range(9):
#         for col in range(9):
#             if sudoku_array[row, col] != 0:
#                 integer = font.render(str(sudoku_array[row, col]), 1, black)
#                 display.blit(integer, (15 + col * 45, 10 + row * 45))
#                 pg.display.flip()

