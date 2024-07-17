import random

MAX = 10
MIN = 1
SIZE = 10

with open("input", 'w') as f :
    f.write("%d\n" % SIZE)
    for i in range (SIZE) :
        deb = random.randint(MIN, MAX)
        fin = random.randint(deb, int(1.4*MAX))
        f.write("%d %d\n" % (deb, fin))
