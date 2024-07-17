import sys; import copy
import pprint

def read() :
    return sys.stdin.readline().strip()

def main():
    for i in range (n) : # for every "erosion"
        currentBoard = copy.deepcopy(board)
        # Time economy : delete all most left, right, upper, lower positions
        board[i] = [False]*width; board[-i-1] = [False]*width # upper / lower
        for k in range (height) :
            board[k][i] = False
            board[k][-i-1] = False
        for row in range(i, height-i-1) :
            if any([currentBoard[row][i] for i in range (width)]) : # if line is not empty
                for ind in range (width-1) :
                    if currentBoard[row][ind] : # if there is something (True)
                        if not(currentBoard[row-1][ind] and currentBoard[row+1][ind] and\
                            currentBoard[row][ind+1] and currentBoard[row][ind-1]):
                            board[row][ind] = False
    printBoard(board); return

def printBoard(l) :
    for i in l :
        print (''.join(['#' if j else '.' for j in i]))

if __name__ == '__main__' :
    # Managing inputs
    n = int(read())
    height, width = map(int, read().split())
    board = [[True if i == '#' else False for i in read()] for _ in range(height)]
    # printBoard(board)
    main()