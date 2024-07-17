import sys
input = sys.stdin.readline
print = sys.stdout.write

def main():
    n, rencontres = map(int, input().split())
    liens = [i for i in range (n)]
    groupes = {i:{i} for i in range (n)}
    for _ in range (rencontres) :
        A, B = map(int, input().split())
        initA, initB = A, B
        while A not in groupes :
            A = liens[A]
        while B not in groupes:
            B = liens[B]
        if A != B :
            print (str(initA) + ' '+ str(initB))
            for e in groupes[B] :
                liens[e] = A
                groupes[A].add(e)
            del groupes[B]

main()