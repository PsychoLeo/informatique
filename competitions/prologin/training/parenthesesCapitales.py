import sys

N = int(input())
o = [sys.stdin.readline().strip() for _ in range (N)]
f = [sys.stdin.readline().strip() for _ in range (N)]

def estValide (s) :
    d = {}

Q = int(input())
for i in range (Q) :
    s = sys.stdin.readline().strip()
    if estValide(s) :
        print("VALIDE")
    else :
        print("INVALIDE")