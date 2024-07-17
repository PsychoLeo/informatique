from math import sqrt

n = int(input())

def erath (n) :
    """
    Renvoie tous les nombres premiers <= n
    """
    primes = [True]*n
    for i in range (2, int(sqrt(n))+1) :
        if primes[i] :
            for j in range (2*i, n, i) :
                primes[j] = False
    for k in range (n) :
        if primes[k] :
            print (k)

erath(n)

# from math import sqrt
# def main():
#    nbCartes = int(input())
#    leJeuSArrete = [True for loop in range(nbCartes+1)]
#    limite = int(sqrt(nbCartes)) + 1
#    for reste in range(2,limite):
#       if leJeuSArrete[reste]:
#          for multiple in range(reste * reste, nbCartes + 1, reste):
#             leJeuSArrete[multiple] = False
#    reponse = [str(reste) for reste in range(nbCartes+1) if leJeuSArrete[reste]]
#    print("\n".join(reponse))
# main()
