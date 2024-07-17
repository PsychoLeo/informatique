import sys

def read() :
    return sys.stdin.readline().strip()

def findOperations(nbCartons) :
    cartons = []
    preds = [0] + [None]*(nbCartons) # predecessors
    for i in range (nbCartons+1) :
        _, *poses = map(int, read().split())
        cartons.append (poses[::-1]) # ruse du vieux sioux
        # ruse : pop() prend O(1) alors que pop(n) prend O(n)
        # donc j'inverse la liste poses lorsqu'elle est prise 
        # en input et j'utilise pop() dans les itérations (car il y 
        # a plus d'itérations que dans l'initialisation)
        # grâce à cette ruse, les 3 derniers test ont fonctionné
    current = 0
    while nbCartons > 0 :
        while cartons[current] :
            elem = cartons[current].pop()
            preds[elem] = current
            print('A', elem)
            current = elem
        print ('R', current)
        current = preds[current]
        nbCartons -= 1

def main() :
    nbCartons = int(input())
    findOperations(nbCartons)

main()