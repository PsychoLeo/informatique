from robot import *

n = tailleCarre()
v = valeurCible()
found = False
vis = [[False]*n for _ in range (n)]

def isValid(lox, hix, loy, hiy) :
    if lox <= hix and loy <= hiy :
        if 0 <= lox < n and 0 <= hix < n and 0 <= loy < n and 0 <= hiy < n :
            return True
    return False

def linearSearch() :
    i, j = 0, n-1
    found = False
    while i < n and j >= 0 and not found:
        a = valeurCase(i, j)
        if a == v :
            found = True
            repondre(i, j)
        elif a < v :
            i += 1
        else :
            j -= 1


def searchCube(lox, loy, hix, hiy) :
    global found, n, v, vis
    if not found and isValid(lox, hix, loy, hiy) :
        midx = (lox + hix) // 2
        midy = (loy + hiy) // 2
        if not vis[midx][midy] :
            vis[midx][midy] = True
        a = valeurCase(midx, midy)
        # print(midx, midy)
        if a == v :
            found = True
            repondre(midx, midy)
        else :
            if a > v :
                searchCube(lox, loy, midx-1, midy-1)
                searchCube(lox, midy, midx-1, hiy)
                searchCube(midx, loy, hix, midy-1)
            else :
                searchCube(midx+1, midy+1, hix, hiy)
                searchCube(lox, midy+1, midx, hiy)
                searchCube(midx+1, loy, hix, midy)

        

def main() :
    # searchCube(0, 0, n-1, n-1)
    linearSearch()

main()
        