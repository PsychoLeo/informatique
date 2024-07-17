import sys

input = sys.stdin.readline 

def solve(n, m, a, b) :
    c = []
    for i in range (n) :
        ci = [(b[i][j]-a[i][j])%3 for j in range (m)]
        c.append(ci)
    for i in range (n) :
        for j in range (m) :
            if c[i][j] != 0 and ((i == n-1) or (j==m-1)): # on essaie de mettre i, j à 0
                return "NO"
            elif c[i][j] != 0 :
                for k in range (i+1, n) :
                    if c[k][j] != 0 :
                        i2 = k
                        break
                for l in range (j+1, m) :
                    if c[i][l] != 0 :
                        j2 = l
                        break 
                try : 
                    d = c[i][j]
                    c[i][j] = 0
                    c[i2][j2] = (c[i2][j2]-d)%3
                    c[i][j2] = (c[i][j2]+d)%3
                    c[i2][j] = (c[i2][j]+d)%3
                except :
                    return "NO"
    return "YES"


def main() :
    t = int(input())
    for _ in range (t) :
        n, m = list(map(int, input().split()))
        a = []
        for _ in range (n) :
            s = input()
            a.append([int(s[i]) for i in range (m)])
        b = []
        for _ in range (n) :
            s = input()
            b.append([int(s[i]) for i in range (m)])
        print(solve(n, m, a, b))

'''
RQ1 : passer A->B équivalent à passer de 0 à B-A (mod 3), ce qui est 
aussi équivalent à passer de B-A à 0
'''

main()