t = 1

from random import randint, sample, choice

with open("input", "w") as f:
    # f.write(str(t) + '\n')
    p = 10
    v = 11
    l = list(range(v))
    m = 0
    for _ in range (t) :
        l2 = []
        used = set()
        for j in range (p) :
            r = randint(1, 3)
            m += r
            smp = sample(l, r)
            matched = choice(smp)
            for x in smp :
                l2.append((j, x))
            used.add(matched)
        f.write(f"{p} {v} {m}\n")
        for a, b in l2 :
            f.write(f"{a} {b}\n")
