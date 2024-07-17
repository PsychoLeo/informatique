import sys
input = sys.stdin.readline
print = sys.stdout.write

def main():
    n, rencontres = map(int, input().split())
    liens = [None]*n
    for i in range (rencontres) :
        A, B = map(int, input().split())
        if A == B :
            while A is not None:
                print(str(A)+ ' ')
                A = liens[A]
            print('\n')
        else :
            predB = B
            predA = A
            while B is not None : # on remonte pour trouver boss B
                predB, B = B, liens[B]
            while A is not None : # on remonte pour trouver boss A
                predA, A = A, liens[A]
            if predB != predA :
                liens[predB] = predA
    # for j in liens :
    #     print(str(j)+' ')
    # print('\n')

main()