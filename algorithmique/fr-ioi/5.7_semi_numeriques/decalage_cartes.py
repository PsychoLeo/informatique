n = int(input())
if n%2 == 0 :
    print(n//2-1, end = ' ')
else :
    print(n//2, end = ' ')
print(n//2)
deb, fin = 2, n
while deb < fin :
    print(deb, fin)
    deb += 1
    fin -= 1
deb, fin = n, 1
while deb > fin :
    print(deb, fin)
    deb -= 1
    fin += 1