from math import ceil

div = [1, 2, 4, 5, 8, 10, 16, 20, 25, 40, 50, 80, 100, 125, 200, 250, 400, 500, 1000, 2000]
for i in div :
    print(i, i+2000//i)
    
M = [1, 2001]
for n in range (1, 2001) :
    if 2000 % n == 0 :
        x = n + 2000//n
    else :
        x = n + ceil(2000/n)
    if x < M[1] :
        M = [n, x]

print(M)