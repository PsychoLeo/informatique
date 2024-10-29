import random

m = 0

for _ in range (1000) :
    k = random.randint(2, 100)
    a, b = 1, 1
    i = 1
    while a % k != 0 :
        a, b = b, (a+b) % k
        i += 1
    m = max(m, i)
    # print(k, i)

print(m)