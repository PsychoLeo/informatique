def main():
    n = int(input())
    l = []
    for i in range (n):
        l.append(int(input()))
    bestSomme = 0
    i = 0
    currSomme = 0
    while i < n :
        if l[i] == 0 :
            bestSomme = max(currSomme, bestSomme)
            currSomme = 0
            i += 1
        else :
            currSomme += l[i]
            i += 1
    print (bestSomme)

main()