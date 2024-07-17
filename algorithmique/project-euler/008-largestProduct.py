import sys
input = sys.stdin.readline

def initInput() :
    global l
    for i in range (20) :
        lst = list(map(int, list(input().strip())))
        l += lst

def main():
    global l
    maxProd = 1
    prod = 1
    i = 0
    n = len(l)
    lenProd = 0 # longueur de notre produit actuel
    while i < n :
        if l[i] == 0 :
            # there will be no product for the next 13 digits
            prod = 1
            lenProd = 0
        else :
            prod *= l[i]
            lenProd += 1
            if lenProd == 13 :
                maxProd = max(prod, maxProd)
                prod //= l[i-12] # diminue longueur de 1
                lenProd -= 1
        i += 1
    print(maxProd)

if __name__ == '__main__':
    l = []
    initInput()
    main()