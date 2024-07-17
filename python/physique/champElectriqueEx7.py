S = 0
n = 100
for i in range (n, -1, -1) :
    for j in range (n, -1, -1) :
        for k in range (n, -1, -1) :
            if (i, j, k) != (0, 0, 0) :
                S += 1/pow(i*i+j*j+k*k, 3/2)
print(S)