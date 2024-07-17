import sys

def read():
    return sys.stdin.readline().strip()

def fusion (A, B) :
    # A et B sont des listes triés
    length = len(A) + len(B)
    A.append(float("+inf"))
    B.append(float("+inf"))
    r = []
    i, j = 0, 0
    for k in range (length) :
        if A[i] > B[j] :
            r.append(B[j])
            j += 1
        else :
            r.append(A[i])
            i += 1
    return r

def tri_fusion (l) :
    n = len(l)
    if n > 1 :
        l1 = tri_fusion(l[:n//2])
        l2 = tri_fusion(l[n//2:])
        return fusion(l1, l2)
    return l


if __name__ == "__main__" :
    n = int(input())
    l = list(map(int ,read().split()))
    for i in tri_fusion(l) :
        print(i, end = ' ')
    print()