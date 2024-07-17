"""
Idées :

- Étudier a_n+1 - a_n
- Montrer que (a_n) converge (décroissante + minorée par 0)
- Téléscopie
- Théorème de Césaro
- Méthode du alpha pour trouver un équivalent de a_n
- Exprimer a_n comme produit de factorielles

"""

a = 1/2
s = a
for n in range (2, 100) :
    print(a)
    a = (1 - 3/(2*n))*a
    s += a
print(s)