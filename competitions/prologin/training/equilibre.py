n = int(input())
from math import log

while n > 1 :
    # n = int(log2(n))
    print(n)
    if n >= 3: 
        nmod3 = n%3
        if nmod3 > 1 :
            n = n//3 + n%3 - 1
        else :
            n = n//3 + n%3
    else :
        n = -1