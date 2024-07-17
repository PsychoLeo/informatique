# We can easily see that x^2 = 0 (mod 10) <=> x = 0 (mod 10)
# The first hidden number is therefore 0
# For the second number, x^2 = 9 (mod 10) <=> x = 3 (mod 10) or x = 7 (mod 10)

from math import sqrt

for k2 in range(10) :
    k2 = str(k2)
    for k3 in range (10) :
        k3 = str(k3)
        for k4 in range (10) :
            k4 = str(k4)
            for k5 in range (10) :
                k5 = str(k5)
                for k6 in range (10) :
                    k6 = str(k6)
                    for k7 in range (10) :
                        k7 = str(k7)
                        for k8 in range (10) :
                            k8 = str(k8)
                            for k9 in range (10) :
                                k9 = str(k9)
                                n = "1"+k9+"2"+k8+"3"+k7+"4"+k6+"5"+k5+"6"+k4+"7"+k3+"8"+k2+"900"
                                n = int(n)
                                if int(sqrt(n))**2 == n :
                                    print(int(sqrt(n)))