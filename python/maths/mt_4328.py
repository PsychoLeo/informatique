epsilon = 1e-8

for n in range (100000) :
    x = n**3-18*(n**2)+115*n-391
    if x >= 0 :
        delta = round(x**(1/3))**3-x
        if abs(delta) < epsilon :
            print(n, x)
            
def P(n) :
    return n**3-18*(n**2)+115*n-391

# print(P(11), P(12), P(25))