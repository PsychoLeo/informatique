import sys

def read() :
    return sys.stdin.readline().strip()

def isValid(a, b, c, d) :
    return a > 0 and b > 0 and c > 0 and d > 0

def fuite_de_clavier(n, k, chaine):
    """
    :param n: taille de la chaîne
    :type n: int
    :param k: taille du mot de passe
    :type k: int
    :param chaine: la chaîne contenant le mot de passe
    :type chaine: list[str]
    """
    numValid = 0
    nMin, nMaj, nNum, nSpec = 0, 0, 0, 0
    for i in range(k): 
        c = chaine[i]
        if c in maj :
            nMaj += 1
        elif c in mini :
            nMin += 1
        elif c in num :
            nNum += 1
        elif c in spec :
            nSpec += 1
    numValid += isValid(nMin, nMaj, nNum, nSpec)
    for i in range (n-k) :
        c1 = chaine[i]
        c2 = chaine[k+i]
        if c1 in maj :
            nMaj -= 1
        elif c1 in mini :
            nMin -= 1
        elif c1 in num :
            nNum -= 1
        elif c1 in spec :
            nSpec -= 1
        if c2 in maj :
            nMaj += 1
        elif c2 in mini :
            nMin += 1
        elif c2 in num :
            nNum += 1
        elif c2 in spec :
            nSpec += 1
        numValid += isValid(nMin, nMaj, nNum, nSpec)
    return numValid


if __name__ == '__main__':
    spec = set("!\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~")
    num = set("0123456789")
    maj = set("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
    mini = set("abcdefghijklmnopqrstuvwxyz")
    n = int(read())
    k = int(read())
    chaine = list(read())
    possiblePwd = fuite_de_clavier(n, k, chaine)
    print(possiblePwd)
