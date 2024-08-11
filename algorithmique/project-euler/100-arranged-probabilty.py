from math import sqrt

n = int(1e12)

while True :
    a = n * (n-1) // 2
    # find p such that p^2 - p = p * (p-1) = a
    sq = int(sqrt(a))
    if (sq+1) * (sq+1) - sq - 1 == a :
        print(sq+1)
        break
    elif sq * sq - sq == a :
        print(sq)
        break
    n += 1
