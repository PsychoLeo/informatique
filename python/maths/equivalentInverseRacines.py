from math import sqrt

s = 0
n = 10000

for i in range (n, 0, -1) :
    s += 1/sqrt(i)
print(s/(2*sqrt(n)))