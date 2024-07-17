an = 1 #a_n
p = 1 # produit des termes
S = 1 # somme des termes de la suite

for n in range (2, 5) :
    an = p+1
    p = p*an
    S += 1/an
print(S)