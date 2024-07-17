def main():
    nbLettres = int(input())
    txt = input()
    carreConcentrique(nbLettres, txt)

def carreConcentrique (n, txt) :
    l = 2*n-1
    carre = []
    currLine = [txt[0]]*l
    for i in range (n):
        for j in range (i, l-i) :
            currLine[j] = txt[-i-1]
        stringLine = ''.join(currLine)
        carre.append(stringLine)
        print (stringLine)
    for line in carre[-2::-1] :
        print (line)

main()