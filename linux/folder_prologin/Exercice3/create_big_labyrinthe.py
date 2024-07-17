import random as rd

# 5≤A≤5000
# 2≤N≤200
# 2≤M≤100
# 0≤ puissance de la divinité ≤100

# Contraintes de performance

#     100≤A≤10000

# 1000≤N≤5000
# 100≤M≤1000
# 0≤
# puissance de la divinité ≤100

A = rd.randint(100,10000) # âme du visiteur
N = rd.randint(1000,5000) # largeur du labyrinthe
M = rd.randint(100,1000) # longueur du labyrinthe


with open("big_labyrinthe.txt", "w") as f:
    #f.writeline(f'{A} {N} {M}')
    f.write(str(A)+"\n")
    f.write(str(N)+"\n")
    f.write(str(M)+"\n")
    for y in range(N):
        line = " ".join([str(rd.randint(0,100)) for _ in range(M)])
        f.write(line+"\n")
