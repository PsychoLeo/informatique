import sys

def read():
    return sys.stdin.readline().strip()

def main():
    n = int(read())
    alveoles = []
    for i in range (n):
        alveoles.append(list(map(int, read().split())))
    print(tempsRemplissage(n, alveoles))

def tempsRemplissage (n, alveoles):
    if n == 1 :
        return alveoles[0]
    for i in range (1, n) :
        for j in range (i+1) :
            if j == 0 :
                alveoles[i][j] += alveoles[i-1][j]
            elif j == i :
                alveoles[i][j] += alveoles[i-1][j-1]
            else :
                alveoles[i][j] += min(alveoles[i-1][j], alveoles[i-1][j-1])
    # print (alveoles)
    return max(alveoles[-1])

main()