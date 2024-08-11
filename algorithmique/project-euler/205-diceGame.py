from random import randint, choice

p = [1, 2, 3, 4]
c = [1, 2, 3, 4, 5, 6]
MAX = 1000*1000
wins = 0

for i in range (MAX) :
    sP = sum(choice(p) for _ in range(9))
    sC = sum(choice(c) for _ in range (6))
    wins += (sP > sC)

print(wins/MAX)