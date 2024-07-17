from math import sqrt

for b in range (1000) :
    for a in range (b) :
        if a + b + sqrt(a*a+b*b) == 1000 :
            c = sqrt(a**2 + b**2)
            if a < b < c :
                print(a*b*c)