import sys
# import pprint

def read() :
    return sys.stdin.readline().strip()

def lineWorks (l) :
    '''Returns if a line works'''
    i = 0
    while i < len(l):
        if l[i] :
            current = l[i]
            numSame = 1
            i += 1
            while i < len(l) and l[i] == current :
                i += 1
                numSame += 1
                if numSame == 5 :
                    return (True, current)
        else :
            i += 1
    return (False, None)


def main():
    # Complexity : O(n^2) approximately
    if n < 5 : # if field is too small
        print (0); return
    # Horizontal
    listsCheck = [board[i] for i in range(n)]
    # Vertical :
    for j in range (n):
        listsCheck.append([board[i][j] for i in range (n)])
    # Diagonals :
    listsCheck.append([board[i][i] for i in range (n)]) # big diagonals
    listsCheck.append([board[i][-i-1] for i in range (n)])
    # pprint.pprint(listsCheck)
    for j in range (1, n-4) : # upper left to lower right
        listsCheck.append([board[i][j+i] for i in range (n-j)])
        listsCheck.append([board[j+i][i] for i in range (n-j)])
    for j in range (-n+4, -1) : # upper right to lower left
        listsCheck.append([board[i][j-i] for i in range (n+j+1)])
        listsCheck.append([board[-j-1+i][-i-1] for i in range (n+j+1)])
    
    # for l in listsCheck :
    #     print (l)

    for line in listsCheck : # check if they work or no
        if lineWorks(line)[0] :
            print (lineWorks(line)[1]); return
    print (0); return

if __name__ == '__main__' :
    # Managing inputs
    n = int(read())
    board = [list(map(int, read().split())) for _ in range(n)]
    main()