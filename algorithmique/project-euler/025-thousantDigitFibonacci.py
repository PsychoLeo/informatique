"""
Un de mes problèmes favoris jusqu'à présent

Pour n suffisamment grand :
    F(n) = (phi^n/sqrt(5))
avec :
    phi = (1+sqrt(5))/2

On cherche donc n tel que :
F(n) >= 10^x
avec x le nombre de chiffres de F(n) -1
Ici, on a x = 999
donc : 
    (phi^n)/sqrt(5) >= 10^x
    ln(phi^n/sqrt(5)) >= ln(10^x)
    n*ln(phi) - ln(sqrt(5)) >= x*ln(10)
    n >= (x*ln(10) + ln(sqrt(5)))/ln(phi)
"""

from math import log, sqrt, e
phi = (1+sqrt(5))/2
x = 999
# print(log(e)) # vérifier que c'est le logarithme népérien
N = (x*log(10) + log(sqrt(5)))/log(phi)
n = int(N) + 1
print(n)