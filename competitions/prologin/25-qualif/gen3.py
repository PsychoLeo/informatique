import random

n = random.randint(2, 20)
alph = list("abcdefg")

with open('input', 'w') as f:
    f.write(str(n) + '\n')
    for i in range (2*n) :
        c1 = random.choice(alph)
        c2 = random.choice(alph)
        f.write(c1+c2+'\n')
