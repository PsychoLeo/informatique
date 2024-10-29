from random import randint

# 5≤A≤5000
# 2≤N≤200
# 2≤M≤100
# 0≤ puissance de la divinité ≤100

A = randint(1, 1000) # âme du visiteur
N = randint(1, 100) # largeur du labyrinthe
M = randint(1, 100) # longueur du labyrinthe

with open("labyrinthe.txt", "w") as f:
    f.write(f'{A}\n')
    f.write(f'{N}\n')
    f.write(f'{M}\n')
    for y in range(N):
        line = " ".join([str(randint(0,100)) for _ in range(M)])
        f.write(f'{line}\n')