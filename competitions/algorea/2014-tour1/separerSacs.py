from robot import *

onpair, onimpair = 0, 0
n = nbSacs()

for i in range (2*n) :
    if i % 2 == 0 and sacDansCase() :
        onpair += 1
    elif i % 2 == 1 and sacDansCase() :
        onimpair += 1