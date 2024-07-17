import sys

def read() :
    return sys.stdin.readline().strip()

def manageInput (n) :
    # Manage input at the beginning of program
    visited, square = [], []
    for i in range (n) :
        inpt = list(map(int, read().split()))
        square.append(inpt)
        for i in inpt :
            visited.append (i)
    return visited, square

def main() :
    # Complexity : O(n)
    numRows = int(read())
    visited, square = manageInput(numRows)
    if sorted(visited) != list(range(1, numRows**2+1)) :
        print ("no")
        return None # if does not contain all integers from 1 to n^2
    sumGrid = sum(square[0])
    left_diagonal = sum([square[i][i] for i in range (numRows)]) != sumGrid
    right_diagonal = sum([square[i][-i-1] for i in range (numRows)]) != sumGrid
    if left_diagonal or right_diagonal :
        print ("no")
        return None # if diagonals do not have same value
    for i in range (numRows) :
        if sum(square[i]) != sumGrid :
            print ("no")
            return None
        if sum([square[j][i] for j in range (numRows)]) != sumGrid :
            print ("no")
            return None
    print ("yes")

if __name__ == '__main__' :
    main()