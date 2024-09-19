import random

t = 1000
with open("input.txt", 'w') as f:
    f.write(str(t) + '\n')
    for i in range (t) :
        n = random.randint(1, 6)
        l = [random.randint(1, n) for _ in range (n)]
        f.write(str(n) + '\n')
        f.write(' '.join([str(x) for x in l]) + '\n')