import sys

def read():
    return sys.stdin.readline().strip()

def venteTele ():
    req.sort(reverse=True)
    stock.sort(reverse=True)
    r = 0
    for hReq, wReq in req : # on part des télés les plus coûteuses en hauteur
        i = 0
        miniWidth = float("+inf")
        optimalIndex = None
        while i < len(stock) and stock[i][0] >= hReq :
            if stock[i][1] < miniWidth and stock[i][1] >= wReq :
                miniWidth = stock[i][1]
                optimalIndex = i
            i += 1
        if optimalIndex is not None :
            r += 1
            del stock[optimalIndex] # on choisit ce paquet
    print (r)


if __name__ == '__main__':
    n = int(read())
    stock = [list(map(int, read().split())) for _ in range (n)]
    m = int(read())
    req = [tuple(map(int, read().split())) for _ in range (m)]
    venteTele()