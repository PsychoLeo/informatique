import random
import os
import time
import filecmp

def generateMatrix(length) :
    return [random.randint(-intl, intl) for _ in range (length)]

def runProgram() :
    n = random.randint(2, tailleListe) # longueur de la liste
    x = random.randint(-intl, intl)
    l = generateMatrix(n)
    with open("in", "w+") as f:
        f.write(f"{x}\n")
        f.write(f"{n}\n")
        for i in generateMatrix(n) :
            f.write(f"{i} ")
    # os.system("compilecpp enterMatriks.cpp")
    os.system("./exec < in > out1")
    os.system("python hubertCode.py < in > out2")
    with open("out1", "r") as f1:
        with open("out2", "r") as f2 :
            if not filecmp.cmp("out1", "out2") :
                return False
    #     if out[0] == "IMPOSSIBLE": 
    #         return
    #     a = list(map(int, out))
    #     b = list(map(int, f.readline().strip().split()))
    # if sum(a)*sum(b) != x :
    #     print(x, n, l) # on a trouvé un cas pour lequel notre programme ne fonctionne pas
    return True

if __name__ == "__main__" :
    tailleListe = 1000*10
    intl = 1000 # limite pour les entiers
    nbTests = 10
    for i in range (nbTests) :
        if not runProgram() :
            print("Found")
            break