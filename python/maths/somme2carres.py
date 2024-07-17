n = 10000
m = n*n
l = [False]*m # s'ils sont somme de 2 carrés

for i in range (n) :
    for j in range (i, n) :
        x = i*i + j*j
        if x < m :
            l[x] = True

# trouver somme de 2 carrés congrue à 3 mod 4
for i in range (m) :
    if i%4 == 3 and l[i] == True :
        print(i)